#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main() {
    //freopen("c.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans = (ans + 1ll * a[i] * a[n+1-i]) % 10007;
    }
    printf("%d\n", ans);
}