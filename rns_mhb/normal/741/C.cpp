#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n;
int a[N], b[N];
int nxt[N], nei[N];
int vis[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[i] = x, b[i] = y;
        nxt[x] = y;
        nxt[y] = x;
    }
    for (int i = 1; i <= n; i ++) {
        nei[i<<1] = i << 1 ^ 1;
        nei[i<<1^1] = i << 1;
    }
    for (int i = 1; i <= 2 * n; i ++) if (!vis[i]) {
        vis[i] = 1;
        int x = nxt[i];
        vis[x] = 2;
        while (!vis[nei[x]]) {
            vis[nei[x]] = 1;
            x = nxt[nei[x]];
            vis[x] = 2;
        }
    }
    for (int i = 1; i <= n; i ++) {
        printf("%d %d\n", vis[a[i]], vis[b[i]]);
    }
}