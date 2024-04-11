#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
using vc = array<int, 10>;

const ll MOD = 1e9 + 7;
int n;
ll fac[205], ifac[205];

vector<ll> mul(vector<ll> &a, vector<ll> &b) {
    int m = a.size();
    vector<ll> res(m);
    for(int i = 0; i < m; i++) {
        for(int j = 0; i + j < m; j++) {
            res[i + j] = (res[i + j] + (a[i] * b[j])) % MOD;
        }
    }
    return res;
}

ll calc(vc a, ll t) {
    vector<vector<ll>> cur(10, vector<ll>(2*t + 1, 0LL));
    for(int d = 0; d <= 9; d++) {
        for(int i = a[d]; i <= t; i++) {
            cur[d][i] = ifac[i];
        }
    }
    for(int d = 1; d <= 9; d++) {
        //cout << "YES" << endl;
        //for(int i = 0; i <= 2*n - 1; i++)
        //    cout << cur[d][i] << " ";
        //cout << endl;
        cur[d] = mul(cur[d], cur[d - 1]);
        //for(int i = 0; i <= 2*t - 1; i++)
        //    cout << cur[d][i] << " ";
        //cout << endl;
    }

    ll tot = 0;
    for(int i = 1; i <= t; i++)
        tot = (tot + cur[9][i] * fac[i]) % MOD;
    return tot;
}

ll inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(int i = 1; i < 205; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
    ifac[204] = inv(fac[204]);
    for(int i = 204; i >= 1; i--)
        ifac[i - 1] = (ifac[i] * i) % MOD;

    //for(int i = 1; i < 10; i++)
    //    cout << fac[i] << " " << ifac[i] << endl;

    cin >> n;
    vc a;
    for(int i = 0; i <= 9; i++)
        cin >> a[i];

    //for(int i = 0; i <= 9; i++)
    //    cout << a[i] << " ";
    //cout << endl;

    ll res = 0;
    res = (res + calc(a, n)) % MOD;
    //cout << res << endl;

    if(a[0] >= 1) {
        a[0]--;
    }
    res = (res - calc(a, n - 1) + MOD) % MOD; 

    int tot = 0;
    for(int d = 0; d <= 9; d++)
        tot += a[d];

    if(tot == 0)
        res = (res + MOD - 1) % MOD;

    cout << res << '\n';
}