#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, k, mn[N], mx[N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) mn[i] = k + 1, mx[i] = 0;
    for (int i = 1, x; i <= k; i ++) {
        scanf("%d", &x);
        mn[x] = min(mn[x], i);
        mx[x] = max(mx[x], i);
    }
    int ans = 0;
    for (int i = 1; i < n; i ++) if (mn[i] > mx[i+1]) ans ++;
    for (int i = 1; i < n; i ++) if (mn[i+1] > mx[i]) ans ++;
    for (int i = 1; i <= n; i ++) if (!mx[i]) ans ++;
    printf("%d\n", ans);
}