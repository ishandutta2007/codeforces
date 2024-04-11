#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 4e4 + 7;
const double EPS = 1e-8;

ll getSqrt(ll x) {
    ll l = 0, r = MAXN;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (mid * mid > x) {
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
    vector <ll> a, b;
    ll good = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll k = getSqrt(x);
        if (k * k == x) {
            good++;
            if (!x) {
                b.push_back(2);
            } else {
                b.push_back(1);
            }
        } else {
            ll l = k * k, r = (k + 1) * (k + 1);
            a.push_back(min(x - l, r - x));
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (good == n / 2) {
        cout << 0;
        return 0;
    }
    ll res = 0;
    if (good > n / 2) {
        for (ll i = 0; i < good - n / 2; i++) {
            res += b[i];
        }
    } else {
        for (ll i = 0; i < n / 2 - good; i++) {
            res += a[i];
        }
    }
    cout << res;
}