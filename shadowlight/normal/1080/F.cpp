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
#define l first
#define r second
#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <pair <ll, ll> > merge(vector <pair <ll, ll> > &a, vector <pair <ll, ll> > &b) {
    vector <pair <ll, ll> > c;
    ll i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        pair <ll, ll> x;
        if (a[i].l < b[j].l) {
            x = {a[i].l, max(a[i].r, b[j].r)};
            i++;
        } else {
            x = {b[j].l, max(a[i].r, b[j].r)};
            j++;
        }
        while (c.size() && x.r <= c.back().r) {
            c.pop_back();
        }
        c.push_back(x);
    }
    return c;
}

struct Tree {
    ll n;
    vector <vector <pair <ll, ll> > > t;
    Tree() {}
    void build(vector <pair <ll, ll> > *a, ll sz) {
        n = sz;
        t.resize(2 * n);
        for (ll i = 0; i < n; i++) {
            t[i + n] = a[i];
        }
        for (ll i = n - 1; i > 0; i--) {
            t[i] = merge(t[2 * i], t[2 * i + 1]);
        }
    }
    bool get(ll l, ll r, ll x, ll y) {
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) {
                ll pos = lower_bound(t[l].begin(), t[l].end(), make_pair(x, 0LL)) - t[l].begin();
                if (pos >= t[l].size() || t[l][pos].r > y) return false;
                l++;
            }
            if (r % 2 == 0) {
                ll pos = lower_bound(t[r].begin(), t[r].end(), make_pair(x, 0LL)) - t[r].begin();
                if (pos >= t[r].size() || t[r][pos].r > y) return false;
                r--;
            }
        }
        return true;
    }
};

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // MY
    ll n, m, k;
    cin >> n >> m >> k;
    vector <pair <ll, ll> > segs[n];
    for (ll i = 0; i < k; i++) {
        ll l, r, p;
        cin >> l >> r >> p;
        p--;
        segs[p].push_back({l, r});
    }
    for (ll i = 0; i < n; i++) {
        sort(segs[i].begin(), segs[i].end());
        vector <pair <ll, ll> > gs;
        for (auto t : segs[i]) {
            while (gs.size() && t.r <= gs.back().r) {
                gs.pop_back();
            }
            gs.push_back(t);
        }
        segs[i] = gs;
    }
    Tree t;
    t.build(segs, n);
    for (ll i = 0; i < m; i++) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        a--, b--;
        cout << (t.get(a, b, x, y) ? "yes" : "no") << endl;
    }
}