#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, m, a[N], x[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    sort(a, a + n); a[n] = 1e9;
    for (int i = 0, s, t; i < m; i ++) {
        scanf("%d %d %d", &s, &x[i], &t);
        if (s > 1) i --, m --;
    }
    sort(x, x + m);
    int ans = 1e9;
    for (int i = 0; i <= n; i ++) {
        ans = min(ans, i + (x + m - lower_bound(x, x + m, a[i])));
    }
    printf("%d\n", ans);
}