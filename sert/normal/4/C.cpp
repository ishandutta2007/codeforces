#include <iostream>
#include <string>
#include <map>
int n;
std::string s;
std::map <std::string, int> m;
int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        if (m.find(s) == m.end()) {
            std::cout << "OK\n";
            m[s] = 1;
        } else
            std::cout << s << m[s]++ << "\n";
    }
}