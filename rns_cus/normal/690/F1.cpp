#include <bits/stdc++.h>
using namespace std;
int deg[11000];
int main() {
    //freopen("1.in", "r", stdin);
    int n, x, y;
    long long ans = 0;
    scanf("%d", &n);
    for(int i = 1; i < n; i ++) {
        scanf("%d%d", &x, &y);
        deg[x] ++;
        deg[y] ++;
    }
    for(int i = 1; i <= n; i ++) {
        ans += deg[i] * (deg[i] - 1) / 2;
    }
    printf("%I64d\n", ans);
}