#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, m, ans;
char str[N];
bool vis[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); scanf("%s", str + 1);
        ans = n; n *= 2; m = 0;
        vis[0] = false;
        for (int i = 1; i <= n; i++) {
            if (str[i] == '(') {
                ans -= vis[m]; vis[m] = true;
                m++;
            } else {
                vis[m] = false;
                m--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}