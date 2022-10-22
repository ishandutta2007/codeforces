#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <ll> > p;

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

ll cnt(ll v) {
    if (!v) {
        return 1;
    }
    return p[0][v - 1];
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
    ll n;
    cin >> n;
    vector <ll> a(n, 0);
    p.resize(n, vector <ll> (n, 0));
    for (ll i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for (ll l = 0; l < n; l++) {
        ll now = 1;
        for (ll r = l; r < n; r++) {
            now = a[r] * now % INF;
            p[l][r] = now;
        }
    }
    vector <ll> d(2 * n + 1, 0);
    vector <ll> res(2 * n, 0);
    d[0] = 1;
    for (ll i = n - 2; i >= 0; i--) {
        vector <ll> nd(2 * n + 1, 0);
        nd[0] = 1;
        nd[1] = 2 * a[i] % INF;
        res[1] = (cnt(i) * nd[1] + res[1]) % INF;
        for (ll x = 2; x <= 2 * (n - i - 1); x++) {
            nd[x] = d[x - 2] * a[i] % INF * a[i] % INF;
            if (x + i - 1 < n) {
                nd[x] += 2 * p[i][i + x - 1];
            }
            nd[x] %= INF;
            res[x] = (cnt(i) * (nd[x] - a[i] * d[x - 2] % INF + INF) % INF + res[x]) % INF;
        }
        d = nd;
    }
    for (ll i = 1; i <= 2 * n - 2; i++) {
        cout << res[i] * rev(2) % INF << " ";
    }
    cout << "\n";
}