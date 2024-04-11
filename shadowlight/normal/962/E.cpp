#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e10 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    ll rd = -INF, bd = -INF;
    ll bmin = INF, rmin = INF;
    ll bmax = -INF, rmax = -INF;
    ll last = -INF;
    ll res = 0;
    bool exist1 = false, exist2 = false;
    ll allp = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        char c;
        cin >> x >> c;
        if (c == 'B') {
            bmin = min(bmin, x);
            bd = max(bd, x - max(bmax, last));
            exist1 = true;
            bmax = x;
        } else if (c == 'R') {
            rmin = min(rmin, x);
            rd = max(rd, x - max(rmax, last));
            exist2 = true;
            rmax = x;
        } else if (c == 'P') {
            if (last == -INF) {
                if (bmin != INF) {
                    res += x - bmin;
                }
                if (rmin != INF) {
                    res += x - rmin;
                }
            } else if (bmin == INF && rmin == INF) {
                res += x - last;
            } else if (rmin == INF) {
                bd = max(bd, x - bmax);
                res += 2 * (x - last) - bd;
                allp += (x - last) - bd;
            } else if (bmin == INF) {
                rd = max(rd, x - rmax);
                res += 2 * (x - last) - rd;
                allp += (x - last) - rd;
            } else {
                bd = max(bd, x - bmax);
                rd = max(rd, x - rmax);
                ll ans1 = 2 * (x - last);
                ll ans2 = 3 * (x - last) - bd - rd;
                res += min(ans1, ans2);
            }
            rmin = INF, rmax = -INF;
            bmin = INF, bmax = -INF;
            rd = -INF, bd = -INF;
            last = x;
        }
    }
    if (last == -INF) {
        if (bmin != INF) {
            res += bmax - bmin;
        }
        if (rmin != INF) {
            res += rmax - rmin;
        }
    } else {
        if (bmin != INF) {
            res += bmax - last;
        }
        if (rmin != INF) {
            res += rmax - last;
        }
    }
    if (!exist1 && !exist2) {
        //nothing
    } else if (!exist1 || !exist2) {
         //res = res - allp;
    }
    cout << res;
}