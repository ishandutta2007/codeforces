#include <bits/stdc++.h>
using namespace std;

#define N 222

bool vis[N], del[N];
char s[N];
int st[N], len[N];

int main() {
    int t, m, x = 0;
    scanf("%d %d", &t, &m);
    while (t --) {
        scanf("%s", s);
        if (s[0] == 'a') {
            int n;
            scanf("%d", &n);
            bool fg = 0;
            for (int k = 1; k <= m - n + 1; k ++) {
                fg = 1;
                for (int i = 0; i < n; i ++) if (vis[k+i]) fg = 0;
                if (fg) {
                    for (int i = 0; i < n; i ++) vis[k+i] = 1;
                    st[++x] = k; len[x] = n;
                    printf("%d\n", x); break;
                }
            }
            if (!fg) puts("NULL");
        }
        else if (s[0] == 'e') {
            int n;
            scanf("%d", &n);
            if (n < 1 || n > x || del[n]) puts("ILLEGAL_ERASE_ARGUMENT");
            else {
                del[n] = 1;
                for (int i = 0; i < len[n]; i ++) vis[st[n]+i] = 0;
            }
        }
        else {
            for (int i = 1, j = 1; i <= m; i ++) if (vis[i]) {
                int k;
                for (k = 1; k <= x; k ++) if (!del[k] && st[k] == i) break;
                for (int l = 0; l < len[k]; l ++) vis[i+l] = 0, vis[j+l] = 1;
                st[k] = j, j += len[k];
            }
        }

    }

    return 0;
}