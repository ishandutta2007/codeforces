#include <bits/stdc++.h>

char c;
std::string str;

int main() {
    std::cin >> str; c = 'z' + 1;
    for (int i = 0; i < str.size(); i++) {
        c = std::min(c, str[i]);
        printf("%s\n", c >= str[i] ? "Mike" : "Ann");
    }
    return 0;
}