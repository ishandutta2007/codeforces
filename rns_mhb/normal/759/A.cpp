#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n;
int p[N], b[N];
int ans;
bool vis[N];

int main() {
    ans = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &b[i]), ans ^= b[i];
    int tot = 0;
    for (int i = 1; i <= n; i ++) if (!vis[i]) {
        tot ++;
        if (p[i] == i) {
            vis[i] = 1;
            continue;
        }
        vis[i] = 1;
        int now = p[i];
        while (now != i) vis[now] = 1, now = p[now];
    }
    if (tot > 1) ans += tot;
    printf("%d\n", ans);
}