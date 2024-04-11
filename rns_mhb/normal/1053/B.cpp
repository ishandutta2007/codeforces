#include<bits/stdc++.h>
using namespace std;

#define N 300010

int n, a[N], s[N], cnt[N][2];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        long long x;
        scanf("%I64d", &x);
        a[i] = __builtin_popcountll(x);
        s[i] = s[i-1] + a[i];
    }
    for(int i = 0; i <= n; i ++) cnt[i][s[i]&1] ++;
    for(int i = 1; i <= n; i ++) cnt[i][0] += cnt[i-1][0], cnt[i][1] += cnt[i-1][1];
    long long ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = i, mx = 0; j; j --) {
            if(mx < a[j]) mx = a[j];
            if(s[i] - s[j-1] >= 120) {
                ans += cnt[j-1][s[i]&1];
                break;
            }
            if((s[i]-s[j-1] & 1 ^ 1) && s[i]-s[j-1] >= 2 * mx) ans ++;
        }
    }
    printf("%I64d\n", ans);
}