#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50, mod = (int)1e9 + 7;
typedef long long ll;

int n;
int p[N];
ll sum[N], dp[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> sum[i];
    for(int i = 1; i < n; i++) cin >> p[i], p[i]--;
    for(int i = n-1; i >= 1; i--) sum[p[i]] += sum[i];
    for(int i = 0; i < n; i++) {
        ll t = sum[0] / __gcd(sum[0], sum[i]);
        if(t <= n) cnt[t] ++;
    }
    for(int i = n; i >= 1; i--) {
        for(int j = 2 * i; j <= n; j += i) cnt[j] += cnt[i];
    }
    for(int i = 1; i <= n; i++) cnt[i] = (cnt[i] == i);
    dp[1] = 1;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) continue;
        for(int j = 2 * i; j <= n; j += i) {
            if(cnt[j] == 1) dp[j] += dp[i], dp[j] %= mod;
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; i++) res += dp[i], res %= mod;
    cout << res << endl;


}