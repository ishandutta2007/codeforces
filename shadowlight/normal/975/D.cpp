#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
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
    ll n, a, b;
    cin >> n >> a >> b;
    map <ll, map <pair <ll, ll>, ll> > cnt;
    ll g1 = 1, g2 = a;
    ll zeros = 0;
    ll good1 = 0, good2 = 0;
    for (ll i = 0; i < n; i++) {
        ll x, vx, vy;
        cin >> x >> vx >> vy;
        if (!vx && !vy) {
            zeros++;
            continue;
        }
        ll d = __gcd(vx, vy);
        ll vx1 = vx / d, vx2 = vy / d;
        if (d < 0) {
            vx1 *= -1, vx2 *= -1;
        }
        if (vx1 == g1 && vx2 == g2) {
            good1++;
            continue;
        }
        if (vx1 == -g1 && vx2 == -g2) {
            good2++;
            continue;
        }
        if (vx1 < 0) {
            vx1 *= -1, vx2 *= -1;
        }
        cnt[a * vx - vy][{vx1, vx2}]++;
    }
    ll res = 0;
    for (auto &p : cnt) {
        ll all = 0;
        for (auto &p1 : p.second) {
            all += p1.second;
        }
        for (auto &p1 : p.second) {
            res += p1.second * (all - p1.second);
        }
    }
    res += 2 * zeros * (good1 + good2) + 2 * good1 * good2;
    cout << res;
}