#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// f(n) = fib(0) * (f(n - 2) + 2^{n - 2}) + fib(1) * (f(n - 3) + 2^{n - 3}) + ... + 
// f(0) = 0
// f(1) = 0
// f(2) = 1
// f(3) = 3
// f(4) = 9
// f(5) = 23
// f(6) = 57
// f(7) = 
const int MAXN = 3e5 + 10;
const ll MOD = 998244353;
const ll INV = 443664157;
ll p2[MAXN], f[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    p2[0] = 1;
    for(int i = 1; i < MAXN; i++)
        p2[i] = (2LL * p2[i - 1]) % MOD;

    for(ll n = 1; n + 1 < MAXN; n++) {
        f[n + 1] = ((3 * n + 1) * p2[n]) % MOD;
        if(n % 2)
            f[n + 1]++;
        else
            f[n + 1]--;
        f[n + 1] = (f[n + 1] * INV) % MOD;
        f[n + 1] = (f[n + 1] + MOD) % MOD;
    }

    int n, m;
    cin >> n >> m;
    vector<string> gr(n);
    ll w = 0;
    for(auto &s : gr) {
        cin >> s;
        for(auto &c : s)
            if(c == 'o')
                w++;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if(gr[i][j] == 'o')
                cnt++;
            else {
                ans = (ans + p2[w - cnt] * f[cnt]) % MOD;
                cnt = 0;
            }
        }
        ans = (ans + p2[w - cnt] * f[cnt]) % MOD;
    }

    for(int j = 0; j < m; j++) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(gr[i][j] == 'o')
                cnt++;
            else {
                ans = (ans + p2[w - cnt] * f[cnt]) % MOD;
                cnt = 0;
            }
        }
        ans = (ans + p2[w - cnt] * f[cnt]) % MOD;
    }

    cout << ans << '\n';
}