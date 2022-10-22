#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <ll> f, pr;

void init() {
    f.resize(MAXN, -1);
    for (ll i = 2; i < MAXN; i++) {
        if (f[i] == -1) {
            f[i] = pr.size();
            pr.push_back(i);
        }
        for (ll j = 0; j <= f[i]; j++) {
            if (pr[j] * i >= MAXN) break;
            f[pr[j] * i] = j;
        }
    }
}

ll all = 0;
vector <ll> ps;

void force(ll maxk, ll cnt = 0, ll pred = -1, ll now = 1) {
    all += (maxk / now) * (cnt % 2 ? -1 : 1);
    for (ll i = pred + 1; i < (ll) ps.size(); i++) {
        force(maxk, cnt + 1, i, now * ps[i]);
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
    init();
    ll t;
    cin >> t;
    for (ll id = 0; id < t; id++) {
        ll x, p, k;
        cin >> x >> p >> k;
        ps.clear();
        ll prv = -1;
        while (p != 1) {
            ll d = pr[f[p]];
            if (d != prv) {
                prv = d;
                ps.push_back(d);
            }
            p /= d;
        }
//        for (ll x : ps) {
//            cout << x << " ";
//        }
//        cout << "\n";
        all = 0;
        force(x);
        ll fr = all;
        ll l = 0, r = INF;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            all = 0;
            force(mid);
            if (all - fr >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << "\n";
    }
}