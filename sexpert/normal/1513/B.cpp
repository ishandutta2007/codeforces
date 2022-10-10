#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

ll fac[MAXN];

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    for(int b = 0; b < 30; b++) {
        int cnt = 0;
        for(auto &x : v)
            cnt += ((x >> b) & 1);
        if(cnt == n)
            for(auto &x : v)
                x -= (1 << b);
    }
    ll c0 = 0;
    for(auto &x : v)
        c0 += (x == 0);
    cout << ((c0 * (c0 - 1)) % MOD * fac[n - 2]) % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(ll i = 1; i < MAXN; i++)
        fac[i] = (i * fac[i - 1]) % MOD;

    int t;
    cin >> t;
    while(t--)
        solve();    
}