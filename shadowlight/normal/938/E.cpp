#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
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
    vector <ll>  f(MAXN, 1);
    for (ll i = 1; i < MAXN; i++) {
        f[i] = f[i - 1] * i % INF;
    }
    ll n;
    cin >> n;
    map <ll, ll> cnt;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        x = -x;
        cnt[x]++;
    }
    ll all = 0;
    ll res = 0;
    for (auto p : cnt) {
        ll v = -p.first, c = p.second;
        all += c;
        if (all > c) {
            res = (res + c * v % INF * power(all, INF - 2)) % INF;
        }
    }
    cout << res * f[n] % INF;
}