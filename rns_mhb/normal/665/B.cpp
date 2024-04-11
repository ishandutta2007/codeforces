#include <bits/stdc++.h>
using namespace std;

#define N 105

int n, m, k;
int p[N*N];
int ans;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i ++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++) {
        int x;
        scanf("%d", &x);
        int pos = 1;
        while (p[pos] != x) pos ++;
        ans += pos;
        for (int l = pos - 1; l >= 1; l --) p[l+1] = p[l];
        p[1] = x;
    }
    printf("%d\n", ans);
    return 0;
}