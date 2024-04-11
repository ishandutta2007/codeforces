#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;
const int inv2 = (int)5e8 + 4;

ll n, m;

int main() {
    cin >> n >> m;

    ll tot = 0;
    for (ll i = 1, j = 0; i <= min(m, n); i = j + 1)  {
        j = min(n/(n/i),m); tot += 1ll*((n/i)%mod)*(1LL * (i+j)%mod*((j-i+1)%mod)%mod*inv2%mod) %mod;
        tot %= mod;
    }
    tot = (n%mod) * (m%mod) - tot;
    tot = (tot % mod + mod) % mod;
    cout << tot << endl;

}