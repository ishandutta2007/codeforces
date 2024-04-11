#include <iostream>
#include <string>

int N;

void a() { std::cout << "Freda's\n"; }
void b() { std::cout << "Rainbow's\n"; }
void c() { std::cout << "OMG>.< I don't know!\n"; }

int main()
{
    std::cin >> N; std::string tmp; std::getline(std::cin, tmp);
    for (int i = 0; i < N; i++) {
        std::string s; std::getline(std::cin, s);
        int M = (int)s.length();
        if (M < 5) c();
        else {
            bool p = (s.substr(M-5, 5) == "lala.");
            bool q = (s.substr(0, 5) == "miao.");
            if (p == q) c();
            else if (p) a();
            else b();
        }
    }
}