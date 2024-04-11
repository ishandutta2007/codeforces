#include <bits/stdc++.h>
#include <bits/extc++.h> /** keep-include */
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;
#define lson(x) 2*x+1
#define rson(x) 2*x+2

const int N = (int)1e5 + 50;

vector<pii> upd[4 * N];

class DSU {
public:
    int n;
    int bad = 0;
    int f[N], sz[N], c[N];
    stack<pii> stk;

    void init(int _n) {
        n = _n;
        rep(i, 0, n) {
            f[i] = i;
            sz[i] = 1;
            c[i] = 0;
        }
    }

    pii findhead(int x) {
        if(x == f[x]) return {x, 0};
        pii res = findhead(f[x]);
        res.second ^= c[x];
        return res;
    }

    void add_edge(int u, int v) {
        auto x = findhead(u), y = findhead(v);
        if(sz[x.first] > sz[y.first]) swap(x,y);
        if(x.first == y.first) {
            if((x.second ^ y.second) == 0) {
                bad++;
                stk.push({-1, -1});
            }
            return ;
        }

        stk.push({x.first, y.first});

        f[x.first] = y.first;
        sz[y.first] += sz[x.first];
        c[x.first] = x.second ^ y.second ^ 1;
    }

    void pop_edge() {
        int x = stk.top().first, y = stk.top().second; stk.pop();
        if(x == -1) {
            bad--;
        } else {
            assert(x != y);
            f[x] = x;
            sz[y] -= sz[x];
            c[x] = 0;
        }
    }
} dsu;

int res[N];

void add_upd(int a, int b, int x, int l, int r, pii p) {
    if(r < a || b < l) return ;
    int mid = (l + r) / 2;
    if(a <= l && r <= b) {
        upd[x].push_back(p);
        return ;
    }
    add_upd(a, b, lson(x), l, mid, p);
    add_upd(a, b, rson(x), mid + 1, r, p);
}

void calc(int x, int l, int r) {
    int stk_size = sz(dsu.stk);
    for (auto p : upd[x]) {
        dsu.add_edge(p.first, p.second);
    }
    if(l == r) {
        res[l] = dsu.bad == 0;
    } else {
        int mid = (l + r) / 2;
        calc(lson(x), l, mid);
        calc(rson(x), mid + 1, r);
    }
    while(sz(dsu.stk) > stk_size) dsu.pop_edge();
}


int n, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    map<pii, int> mp;
    rep(i, 1, q + 1) {
        int x, y; cin >> x >> y; x--, y--;
        if(x > y) swap(x, y);
        if(mp[{x, y}]) {
            add_upd(mp[{x, y}] - 1, i - 2, 0, 0, q - 1, {x, y});
            mp[{x, y}] = 0;
        } else {
            mp[{x, y}] = i;
        }
    }
    for (auto pp : mp) {
        pii p = pp.first;
        int x = pp.second;
        if(x != 0) {
            add_upd(x - 1, q - 1, 0, 0, q - 1, p);
        }
    }
    dsu.init(n);
    calc(0, 0, q - 1);
    rep(i, 0, q) cout << (res[i] ? "YES" : "NO") << '\n';



}