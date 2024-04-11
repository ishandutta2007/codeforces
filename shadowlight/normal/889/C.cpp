#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * b % INF;
    if (k % 2) {
        return b * a % INF;
    } else {
        return b;
    }
}

ll rev(ll x) {
    return power(x, INF - 2);
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ll n, k;
    cin >> n >> k;
    vector <ll> fact(MAXN, 0);
    vector <ll> rfact(MAXN,  0);
    fact[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % INF;
    }
    for (ll i = 0; i < MAXN; i++) {
        rfact[i] = rev(fact[i]);
    }
    vector <ll> pref(MAXN, 0);
    vector <ll> d(MAXN, 0);
    for (ll i = 0; i <= n; i++) {
        if (i <= k) {
            continue;
        }
        d[i] = fact[i - 2] * ((i - k - 1) + (pref[i - 1] - pref[i - k - 1] + INF) % INF) % INF;
        //cout << i << " " << d[i] << "\n";
        pref[i] = (pref[i - 1] + d[i] * rfact[i - 1]) % INF;
    }
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        res += d[i + 1] * fact[n - 1] % INF * rfact[i] % INF;
        res %= INF;
    }
    cout << res;
}