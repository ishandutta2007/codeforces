#include <bits/stdc++.h>
using namespace std;
#define N 105

int n, m, b, g, d, by, gl;
bool fl = 0, vis[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &m);
    d = __gcd(m, n);
    scanf("%d", &b);
    for (int i = 0; i < b; i ++) scanf("%d", &by), vis[by%d] = 1;
    scanf("%d", &g);
    for (int i = 0; i < g; i ++) scanf("%d", &gl), vis[gl%d] = 1;
    
    for (int i = 0; i < d; i ++) if (!vis[i]) fl = 1;
    if (fl) puts("No");
    else puts("Yes");

    return 0;
}