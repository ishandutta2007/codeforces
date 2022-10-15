#include <bits/stdc++.h>

int T, n, ans, cnt;
std::string s;

int main() {
    for (std::cin >> T; T; T--) {
        std::cin >> s;
        n = s.size(); cnt = 0; ans = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                if (cnt > 0) {
                    cnt--; ans -= 2;
                } else {
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}