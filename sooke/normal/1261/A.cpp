#include <bits/stdc++.h>

const int N = 1e4 + 5;

int T, n, m, k;
char s[N], t[N];
std::vector<std::pair<int, int>> ans;

int main() {
    for (scanf("%d", &T); T; T--) {
        scanf("%d%d%s", &n, &k, s); m = 0; k--; ans.clear();
        for (int i = 0; i < k; i++) { t[m++] = '('; t[m++] = ')'; }
        for (int i = 0; i < n / 2 - k; i++) { t[m++] = '('; }
        for (int i = 0; i < n / 2 - k; i++) { t[m++] = ')'; }
        for (int l = 0; l < n; l++) {
            if (s[l] != t[l]) {
                for (int r = l + 1; r < n; r++) {
                    if (s[r] == t[l]) {
                        ans.push_back({l, r});
                        std::reverse(s + l, s + r + 1);
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans.size());
        for (auto tmp : ans) { printf("%d %d\n", tmp.first + 1, tmp.second + 1); }
    }
    return 0;
}