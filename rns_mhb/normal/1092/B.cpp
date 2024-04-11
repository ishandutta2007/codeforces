#include<bits/stdc++.h>
using namespace std;

int n, a[111];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 1, j = -1; i <= n; i ++, j *= -1) ans += a[i] * j;
    printf("%d\n", ans);
}