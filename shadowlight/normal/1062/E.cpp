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

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll LOGN = 25;

ll n;

vector <vector <ll> > gr;
vector <ll> he;

vector <vector <ll> > binup;

void dfs(ll v, ll p, ll h) {
    binup[0][v] = p;
    he[v] = h;
    for (ll i = 1; i < LOGN; i++) {
        if (binup[i - 1][v] == -1) continue;
        binup[i][v] = binup[i - 1][binup[i - 1][v]];
    }
    for (ll u : gr[v]) {
        dfs(u, v, h + 1);
    }
}

ll up(ll v, ll h) {
    for (ll i = LOGN - 1; i >= 0; i--) {
        if (h < (1 << i)) continue;
        h -= 1 << i;
        v = binup[i][v];
    }
    return v;
}

ll lca(ll v, ll u) {
    if (he[v] < he[u]) swap(v, u);
    v = up(v, he[v] - he[u]);
    if (v == u) return v;
    for (ll i = LOGN - 1; i >= 0; i--) {
        if (binup[i][v] == binup[i][u]) continue;
        v = binup[i][v];
        u = binup[i][u];
    }
    return binup[0][v];
}

vector <vector <pair <ll, ll> > > sparse;

pair <ll, ll> get_min(ll l, ll r) {
    ll k = log2(r - l + 1);
    return min(sparse[k][l], sparse[k][r - (1 << k) + 1]);
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
    ll q;
    cin >> n >> q;
    gr.resize(n);
    he.resize(n, 0);
    binup.resize(LOGN, vector <ll> (n, -1));
    for (ll i = 1; i < n; i++) {
        ll p;
        cin >> p;
        p--;
        gr[p].push_back(i);
    }
    dfs(0, -1, 0);
    vector <pair <ll, ll> > all;
    for (ll i = 0; i < n - 1; i++) {
        ll x = lca(i, i + 1);
        all.push_back({he[x], x});
    }
    sparse.resize(LOGN, vector <pair <ll, ll> > (n - 1));
    sparse[0] = all;
    for (ll i = 1; i < LOGN; i++) {
        for (ll j = 0; j < n - 1; j++) {
            if (j + (1 << (i - 1)) >= n - 1) continue;
            sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        l--, r -= 2;
        ll lt = l - 1, rt = r;
        auto t = get_min(l, r);
        while (rt - lt > 1) {
            ll mid = (lt + rt) / 2;
            auto t1 = get_min(l, mid);
            if (t1.second == t.second) {
                rt = mid;
            } else {
                lt = mid;
            }
        }
        ll v;
        if (lt != l - 1) {
            auto t1 = get_min(l, lt);
            v = t1.second;
        } else {
            v = l;
        }
        pair <ll, ll> res1;
        if (l == r) {
            res1 = {he[r + 1], r + 1};
        } else {
            res1 = get_min(l + 1, r);
        }
        //cout << lt + 3 << "\n";
        if (lt + 3 <= r) {
            auto t2 = get_min(lt + 3, r);
            v = lca(v, t2.second);
        } else if (lt + 3 == r + 1) {
            v = lca(v, r + 1);
        }
        if (res1.first > he[v]) {
            v = res1.second;
            lt = l - 2;
        }
        cout << lt + 3 << " " << he[v] << "\n";
    }
}