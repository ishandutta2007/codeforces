#include <bits/stdc++.h>
using namespace std;

#define N 300100

int n;
char s[N];
bool vis[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        bool fg = true, ok = false;
        for (int i = 1; i <= n; i ++) if (s[i] == '>') fg = false;
        ok |= fg, fg = true;
        for (int i = 1; i <= n; i ++) if (s[i] == '<') fg = false;
        ok |= fg;
        if (ok) printf("%d\n", n);
        else {
            for (int i = 1; i <= n; i ++) vis[i] = 0;
            for (int i = 1; i <= n; i ++) {
                int x = i, y = i % n + 1;
                if (s[x] == '-') vis[x] = vis[y] = 1;
            }
            int ans = 0;
            for (int i = 1; i <= n; i ++) if (vis[i]) ans ++;
            printf("%d\n", ans);
        }
    }

    return 0;
}