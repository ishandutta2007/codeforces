#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll power(ll a, ll k) {
    if (!k) return 1;
    ll b = power(a, k / 2);
    b = b * b % INF;
    if (k % 2) {
        return a * b % INF;
    } else {
        return b;
    }
}

ll f[MAXN], rf[MAXN];

ll rev(ll a) {
    return power(a, INF - 2);
}

void init() {
    f[0] = 1;
    rf[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        f[i] = f[i - 1] * i % INF;
        rf[i] = rev(f[i]);
    }
}

ll C(ll n, ll k) {
    return f[n] * rf[k] % INF * rf[n - k] % INF;
}

ll Stirling(ll n, ll k) {
    ll res = 0;
    for (ll i = 0; i <= k; i++) {
        res = (res + ((k + i) % 2 ? INF - 1 : 1LL) * C(k, i) % INF * power(i, n)) % INF;
    }
    return res * rf[k] % INF;
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
    init();
    ll n, k;
    cin >> n >> k;
    ll W = 0;
    for (ll i = 0; i < n; i++) {
        ll w;
        cin >> w;
        W += w;
    }
    W %= INF;
    ll cf = (Stirling(n, k) + Stirling(n - 1, k) * (n - 1)) % INF;
    cout << W * cf % INF;
}