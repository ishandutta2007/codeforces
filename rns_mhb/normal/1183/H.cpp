#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 111

char s[N];
ll dp[N][26], sum[N];

int main() {
    int n;
    ll k;
    scanf("%d%I64d", &n, &k);
    scanf("%s", s + 1);
    sum[0] = 1;
    for(int i = 1; i <= n; i ++) {
        int c = s[i] - 'a';
        for(int j = i; j; j --) {
            ll tmp = dp[j][c];
            dp[j][c] = sum[j-1];
            sum[j] += dp[j][c] - tmp;
        }
    }
    ll ans = 0;
    for(int i = n; i >= 0; i --) {
        if(sum[i] < 0) break;
        if(sum[i] >= k) {
            ans += (n - i) * k;
            printf("%I64d\n", ans);
            return 0;
        }
        k -= sum[i];
        ans += (n - i) * sum[i];
    }
    puts("-1");
}