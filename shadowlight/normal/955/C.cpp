#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 2e18 + 7;
const ll MAXN = 1e3 + 7;
const double EPS = 1e-30;
const ll SZ = 61;

vector <ll> cntd(SZ, 0);

void init() {
    for (ll i = 2; i < SZ; i++) {
        ll now = i;
        for (ll j = 2; j <= i; j++) {
            ll cnt = 0;
            while (now % j == 0) {
                cntd[i]++;
                now /= j;
                cnt++;
            }
            if (cnt > 1) {
                cntd[i] = -1;
                break;
            }
        }
    }
}

ll calc(ll l, ll r) {
    ll res = 0;
    if (l == 1) {
        res++;
        l++;
    }
    for (ll i = 2; i < SZ; i++) {
        if (cntd[i] == -1) continue;
        ll rc = floor(powl(r, 1.0 / i) + EPS);
        ll lc = ceil(powl(l, 1.0 / i) - EPS);
        while (powl(lc - 1, i) >= l) lc--;
        while (powl(lc, i) < l) lc++;
        while (powl(rc, i) > r) rc--;
        while (powl(rc + 1, i) <= r) rc++;
        if (lc <= rc) {
            res += (rc - lc + 1) * (cntd[i] % 2 ? 1 : -1);
        }
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
    init();
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        cout << calc(l, r) << "\n";
    }
}