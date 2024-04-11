#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll manh(pair <ll, ll> a, pair <ll, ll> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll n;
set <ll> exist;
set <pair <ll, ll> > q;
vector <pair <ll, ll> > a;

ll get(ll x, ll y) {
    x = (x + n) % n;
    y = (y + n) % n;
    return manh(a[x], a[y]);
}

ll pred(ll v) {
    auto it = exist.lower_bound(v);
    if (it == exist.begin()) {
        it = exist.end();
    }
    it--;
    return *it;
}

ll nxt(ll v) {
    auto it = exist.upper_bound(v);
    if (it == exist.end()) {
        it = exist.begin();
    }
    return *it;
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
    cin >> n;
    a.resize(n);
    vector <ll> xmi, ymi, xma, yma;
    vector <ll> res(n + 1, 0);
    ll xmin = INF, ymin = INF, xmax = -INF, ymax = -INF;
    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        a[i] = {x, y};
        if (x < xmin) {
            xmi.clear();
            xmi.push_back(i);
            xmin = x;
        } else if (x == xmin) {
            xmi.push_back(i);
        }
        if (x > xmax) {
            xma.clear();
            xma.push_back(i);
            xmax = x;
        } else if (x == xmax) {
            xma.push_back(i);
        }
        if (y < ymin) {
            ymi.clear();
            ymi.push_back(i);
            ymin = y;
        } else if (y == ymin) {
            ymi.push_back(i);
        }
        if (y > ymax) {
            yma.clear();
            yma.push_back(i);
            ymax = y;
        } else if (y == ymax) {
            yma.push_back(i);
        }
    }
    if (n == 3) {
        cout << get(0, 1) + get(1, 2) + get(2, 0) << "\n";
        return 0;
    }
    vector <ll> all;
    for (ll x : ymi) {
        all.push_back(x);
    }
    for (ll x : xmi) {
        all.push_back(x);
    }
    for (ll x : yma) {
        all.push_back(x);
    }
    for (ll x : xma) {
        all.push_back(x);
    }
    sort(all.begin(), all.end());
    for (ll i = 0; i < (ll) all.size(); i++) {
        for (ll j = i + 1; j < (ll) all.size(); j++) {
            if (all[i] == all[j]) continue;
            ll v = all[i], u = all[j];
            for (ll k = 0; k < n; k++) {
                if (k == v || k == u) continue;
                res[3] = max(res[3], get(v, u) + get(u, k) + get(k, v));
            }
        }
    }
    res[4] = 2 * (xmax - xmin) + 2 * (ymax - ymin);
    if (res[3] == 0) {
        res[3] = res[4];
    }
    cout << res[3] << " ";
    for (ll i = 4; i <= n; i++) {
        cout << res[4] << " ";
    }
}