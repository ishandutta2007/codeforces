#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n, k, m, d;

ll calc(ll x) {
    if (!x) {
        return INF;
    }
    ll res = n / x / k;
    ll a = (!res ? n : n % (x * k));
    if (a >= x) {
        res++;
    }
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
    cin >> n >> k >> m >> d;
    ll now = m;
    ll res = 0;
    for (ll i = 1; i <= d; i++) {
        ll l = 0, r = now;
        if (calc(now) > i) continue;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (calc(mid) <= i) {
                r = mid;
            } else {
                l = mid;
            }
        }
        res = max(res, now * i);
        now = l;
    }
    cout << res;
}