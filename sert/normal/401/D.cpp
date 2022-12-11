#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
const ld EPS = 1e-10;
const ld INF = (ll)1e9 + 34;
const ll N = (ll)1e6 + 34;

string s;
ll m;

ll dp[1 << 18][100];

ll fac(ll x) {
    ll res = 1;
    for (int i = 1; i <= x; i++)
        res *= i;
    return res;
}

int mp[100];

int main() {
    cin >> s >> m;
    ll n = s.length();
    dp[0][0] = 1;
    for (ll msk = 0; msk < (1 << n); msk++)
    for (ll md = 0; md < m; md++) {
        for (int i = 0; i < n; i++)
            if ((msk & (1 << i)) == 0)
                if (msk > 0 || s[i] != '0')
                    dp[msk | (1 << i)][(md * 10 + s[i] - '0' + m) % m] += dp[msk][md];
    }

    for (int i = 0; i < n; i++)
        mp[s[i] - '0']++;
    ll ko = 1;
    for (int i = 0; i < 10; i++)
        ko *= fac(mp[i]);

    cout << dp[(1 << n) - 1][0] / ko;

    return 0;
}