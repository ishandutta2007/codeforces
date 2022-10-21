#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500, mod = 998244353;
typedef long long ll;

int n;
int cost[N], pw2[N];
ll cnt[N];

int main() {
    pw2[0] = 1;
    for(int i = 1; i < N; i++) pw2[i] = 2 * pw2[i-1] % mod;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &cost[i]);
    ll res = 0;
    for(int d = 1; d <= n-1; d++){
        cnt[d] = 1LL * pw2[n-1-d] * 2 % mod;
        if(n >= 3 && d <= n-2) cnt[d] += 1LL * pw2[n-2-d] * (n-1-d) % mod;
    }
    cnt[n] = 1;
    for(int d = n-1; d >= 1; d--) cnt[d] += cnt[d+1], cnt[d] %= mod;
    for(int d = 1; d <= n; d++) res += cnt[d] * cost[d] % mod;
    res %= mod;
    cout << res;
}