#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const ll MAXN = 2e6 + 7;
const double EPS = 1e-8;
const ll MOD = 998244353;

ll sqrt3(ll x) {
    ll l = 1, r = MAXN;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (x < mid * mid * mid) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
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
    vector <ll> a(n);
    map <ll, ll> cnt;
    vector <bool> good(n, false);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
        ll k = sqrtl(x);
        if (k * k == x) {
            good[i] = true;
            ll m = sqrtl(k);
            if (m * m == k) {
                cnt[m] += 4;
            } else {
                cnt[k] += 2;
            }
        }
        ll d = sqrt3(x);
        //cout << x << " " << d << "\n";
        if (d * d * d == x) {
            good[i] = true;
            cnt[d] += 3;
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (good[i] || a[i] == a[j]) continue;
            ll x = __gcd(a[i], a[j]);
            if (x != 1) {
                good[i] = true;
                cnt[x]++;
                cnt[a[i] / x]++;
                break;
            }
        }
    }
    map <ll, ll> all_bad;
    for (ll i = 0; i < n; i++) {
        if (!good[i]) {
            all_bad[a[i]]++;
        }
    }
    ll res = 1;
    for (auto p : cnt) {
        res = res * (p.second + 1) % MOD;
    }
    for (auto p : all_bad) {
        res = res * (p.second + 1) % MOD * (p.second + 1) % MOD;
    }
    cout << res;
}