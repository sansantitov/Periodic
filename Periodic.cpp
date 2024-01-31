#include <iostream>
#include <string>

bool IsKPeriodic(std::string& text, int k)
{
    int count = 0; //переменная счетчика числа вхождений подстроки в строку
    if (text.length() == 0) return false;//проверка на пустую строку
    
    std::string subtext = text.substr(0, k); //начальная подстрока
    for (int i = 0; i < text.length(); ++i) //поиск числа вхождений подстроки в строку:
        if (text[i] == subtext[0])
        {
            if (text.substr(i, subtext.length()) == subtext)
            {
                ++count;
                i += (int)subtext.length() - 1;
            }
        }
    return (subtext.length() * count) == text.length(); //все подстроки должны укладываться в строку
    
}

int main()
{
    setlocale(LC_ALL, "Rus");
    while (true)
    {
        std::string txt;
        int k;
        std::cout << "Строка (закончить-0): ";
        std::cin >> txt;
        if (txt == "0") break;
        std::cout << "Кратность: ";
        std::cin >> k;
        bool ret = IsKPeriodic(txt, k);
        std::cout << "Строка " << txt << (ret?"":" не") << " является кратной " << k << std::endl;
    }
    
    return 0;
}