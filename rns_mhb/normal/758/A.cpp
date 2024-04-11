#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, mx = 0, a[101], ans = 0, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) scanf("%d", a + i), mx = max(mx, a[i]);
    for(i = 1; i <= n; i ++) ans += mx - a[i];
    printf("%d\n", ans);
}