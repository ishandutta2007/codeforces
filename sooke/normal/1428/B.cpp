#include <bits/stdc++.h>

int T, n, ans;
std::string s;

bool check() {
    bool l = false, r = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '<') { l = true; }
        if (s[i] == '>') { r = true; }
        if (s[i] == '-') { ans++; }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '-' && s[(i + 1) % n] != '-') { ans++; }
    }
    return l && r;
}

int main() {
    for (std::cin >> T; T; T--) {
        std::cin >> n >> s; ans = 0;
        if (!check()) {
            std::cout << n << std::endl; continue;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}