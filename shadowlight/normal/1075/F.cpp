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

map <ll, ll> we, root;
map <ll, ll> where;

ll last = 0;

vector <vector <ll> > all;

void create(ll v) {
    if (!root.count(v)) {
        root[v] = v;
        all.push_back({v});
        where[v] = last++;
        we[v] = 0;
    }
}

void uni(ll v, ll u, ll w) {
    create(v);
    create(u);
    ll nv = where[v], nu = where[u];
    if (nv == nu) return;
    if (all[nv].size() > all[nu].size()) {
        swap(nv, nu);
        swap(v, u);
    }
    ll val = we[v] ^ we[u] ^ w;
    for (ll x : all[nv]) {
        we[x] ^= val;
        root[x] = root[u];
        where[x] = nu;
        all[nu].push_back(x);
    }
    all[nv].clear();
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
    int q;
    cin >> q;
    ll last = 0;
    for (ll i = 0; i < q; i++) {
        ll t;
        cin >> t;
        ll l, r, x;
        cin >> l >> r;
        l ^= last, r ^= last;
        if (l > r) swap(l, r);
        r++;
        if (t == 1) {
            cin >> x;
            x ^= last;
            uni(l, r, x);
        } else {
            create(l);
            create(r);
            if (where[l] != where[r]) {
                cout << "-1\n";
                last = 1;
            } else {
                last = (ll) (we[l] ^ we[r]);
                cout << last << "\n";
            }
        }
        //cout << "\n";
    }
}