#include <bits/stdc++.h>

int T, n;
std::string str;

int main() {
    for (scanf("%d", &T); T; T--) {
        std::cin >> n >> str;
        std::sort(str.begin(), str.end());
        std::cout << str << std::endl;
    }
    return 0;
}