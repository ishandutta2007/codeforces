#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 998244353;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * b % INF;
    if (k % 2) {
        return a * b % INF;
    } else {
        return b;
    }
}

ll rev(ll a) {
    return power(a, INF - 2);
}

ll n, m, a;

ll cnt(ll len) {
    ll res = (power(a, 2 * len) + power(a, len)) * rev(2) % INF;
    return res;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n >> m >> a;
    vector <ll> b(m);
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    ll res = 1;
    res = cnt(b[0]);
    for (ll i = 1; i < m; i++) {
        res = res * cnt(b[i] - b[i - 1]) % INF;
    }
    res = res * power(a, n - 2 * b[m - 1]) % INF;
    cout << res;
}