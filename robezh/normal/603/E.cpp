#include <bits/stdc++.h>
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

const int N = (int)5e5 + 50;

vector<pii> upd[4 * N];

class DSU {
public:
    int n;
    int odd = 0;
    int f[N], sz[N];
    stack<pii> stk;

    void init(int _n) {
        n = _n;
        rep(i, 0, n) {
            f[i] = i;
            sz[i] = 1;
        }
        odd = _n;
    }

    int findhead(int x) {
        return f[x] == x ? x : findhead(f[x]);
    }

    void add_edge(int u, int v) {
        auto x = findhead(u), y = findhead(v);
        if(sz[x] > sz[y]) swap(x,y);
        if(x == y) return;

        stk.push({x, y});

        f[x] = y;
        odd -= (sz[y] % 2) + (sz[x] % 2);
        sz[y] += sz[x];
        odd += (sz[y] % 2);
    }

    void pop_edge() {
        int x = stk.top().first, y = stk.top().second; stk.pop();
        assert(x != y);

        odd -= (sz[y] % 2);
        f[x] = x;
        sz[y] -= sz[x];
        odd += (sz[y] % 2) + (sz[x] % 2);
    }
} dsu;


struct edge {
    int u, v, l, idx;
};

vector<edge> es;
int pt;
int n, m;
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
        while(pt < sz(es) && dsu.odd) {
            if(es[pt].idx <= l) dsu.add_edge(es[pt].u, es[pt].v);
            add_upd(es[pt].idx, l - 1, 0, 0, m - 1, {es[pt].u, es[pt].v});
            pt++;
        }
//        cout << l << ": ";
//        rep(i, 0, n) cout << dsu.f[i] << " ";
//        cout << endl;
        res[l] = (dsu.odd ? -1 : es[pt - 1].l);
    } else {
        int mid = (l + r) / 2;
        calc(rson(x), mid + 1, r);
        calc(lson(x), l, mid);
    }
    while(sz(dsu.stk) > stk_size) dsu.pop_edge();
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    dsu.init(n);

    rep(i, 0, m) {
        int u, v, l; cin >> u >> v >> l; u--, v--;
        es.push_back({u, v, l, i});
    }
    sort(all(es), [](const edge &e1, const edge &e2) {
        return e1.l < e2.l;
    });

    calc(0, 0, m - 1);
    rep(i, 0, m) cout << res[i] << "\n";

}