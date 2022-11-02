#include<bits/stdc++.h>
using namespace std;

#define N 200010

int n, a[N], s;

int main() {
    scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int m = n + 1 >> 1;
    long long ans = 0;
    for(int i = 1; i < m; i ++) if(a[i] > s) ans += a[i] - s;
    ans += abs(a[m] - s);
    for(int i = m + 1; i <= n; i ++) if(a[i] < s) ans += s - a[i];
    printf("%I64d\n", ans);
}