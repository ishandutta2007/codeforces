#include <bits/stdc++.h>

const int N = 50005;

int T, n, pos, f[N];

std::string ans;

int main() {
    for (std::cin >> T; T; T--) {
        std::cin >> n; pos = -1;
        for (int i = 50000; i >= 1; i--) {
            f[i] = 0;
            long long x = i * (i + 1ll) / 2;
            for (; n >= x; n -= x) { f[i]++; }
            if (f[i] > 0 && pos == -1) { pos = i; }
        }
        ans.clear();
        for (int i = pos; i >= 0; i--) {
            for (; f[i]; f[i]--) { ans += "1"; }
            ans += "3";
        }
        std::cout << ans + "7" << std::endl;
    }
    return 0;
}