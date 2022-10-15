#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, k, ans, cnt;
char str[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); k = read();
        scanf("%s", str + 1);
        ans = cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (str[i] == 'W') {
                ans++;
                if (str[i - 1] == 'W') {
                    ans++;
                }
            } else {
                cnt++;
            }
        }
        if (ans == 0) {
            if (k > 0) {
                ans = 1 + 2 * (k - 1); 
            }
        } else {
            if (k > cnt) {
                ans = 1 + 2 * (n - 1);
            } else {
                std::vector<int> a;
                for (int i = 1, j = -1; i <= n; i++) {
                    if (str[i] == 'W') {
                        if (j != -1) {
                            if (i - j - 1 > 0) {
                                a.push_back(i - j - 1);
                            }
                        }
                        j = i;
                    }
                }
                a.push_back(1e9);
                std::sort(a.begin(), a.end());
                std::reverse(a.begin(), a.end());
                for (; k; k--) {
                    if (!a.empty()) { a[a.size() - 1]--; ans += 2; }
                    for (; !a.empty() && a.back() == 0; a.pop_back(), ans++);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}