#include <bits/stdc++.h>

const int inf = 1e9;

int T, n;
std::string s;

int solve() {
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        int f00 = 0, f01 = 0, f10 = 0, f11 = 0;
        for (int i = 1, j = -123; i <= n; i++) {
            if (s[i] != c) { continue; }
            int g00 = f00, g01 = f01, g10 = f10, g11 = f11;
            if (i - j == 1) {
                f00 = inf;
                f01 = g10 + 1;
                f10 = g11;
                f11 = std::min(g01, g11) + 1;
            } else if (i - j == 2) {
                f00 = f01 = inf;
                f10 = std::min(g01, g11);
                f11 = std::min(std::min(std::min(g00, g01), g10), g11) + 1;
            } else {
                ans += std::min(std::min(std::min(f00, f01), f10), f11);
                f00 = f10 = 0;
                f01 = f11 = 1;
            }
            j = i;
        }
        ans += std::min(std::min(std::min(f00, f01), f10), f11);
    }
    return ans;
}

int main() {
    for (std::cin >> T; T; T--) {
        std::cin >> s; n = s.size(); s = " " + s;
        std::cout << solve() << std::endl;
    }
    return 0;
}