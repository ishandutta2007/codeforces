#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)1e5 + 50;
const ll INF = (ll)1e18;

int n, m, q;

ll res[N];
multiset<int> G[N];
multiset<ll> S3;
map<pii, pii> in;

struct Eg {
    int tl, tr, u, v, w;
};

vector<Eg> egs;

ll get(int v) {
    if(sz(G[v]) < 3) return INF;
    auto it = G[v].begin();
    ll s = 0;
    rep(i, 0, 3) s += *(it++);
    return s;
}

ll rs[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int col[N];


struct DSU {
    int f[N];
    ll mn[N];

    void init() {
        iota(f, f + q + 1, 0);
        fill(mn, mn + q + 1, INF);
    }

    int find(int u) {
        return f[u] == u ? u : f[u] = find(f[u]);
    }

    void unite(int u, int v) {
        f[find(u)] = find(v);
    }

    void paint(int l, int r, int w) {
        int cur = l;
        int la = -1;
        while(cur <= r) {
            if(mn[cur] == INF) {
                mn[cur] = w;
            } else {
                cur = find(cur);
            };

            if(la != -1) unite(la, cur);
            la = cur;
            cur += 1;
        }
    }

} dsu[2];

void solve() {
    rep(i, 0, n) col[i] = rng() % 2;

    dsu[0].init(), dsu[1].init();
    for(auto &e : egs) {
        if(col[e.u] != col[e.v]) continue;
        dsu[col[e.u]].paint(e.tl, e.tr, e.w);
    }

    rep(i, 0, q + 1) res[i] = min(res[i], dsu[0].mn[i] + dsu[1].mn[i]);


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        if(u > v) swap(u, v);
        G[u].insert(w);
        G[v].insert(w);
        in[{u, v}] = {0, w};
    }

    rep(i, 0, n) {
        rs[i] = get(i);
        S3.insert(rs[i]);
    }
    res[0] = *S3.begin();

    cin >> q;
    rep(i, 1, q + 1) {
        int tp, u, v, w;
        cin >> tp;
        if(tp == 0) {
            cin >> u >> v; u--, v--;
            if(u > v) swap(u, v);
            auto p = in[{u, v}];

            for (int x : {u, v}) {
                S3.erase(S3.find(rs[x]));
                G[x].erase(G[x].find(p.second));
                rs[x] = get(x);
                S3.insert(rs[x]);
            }

            in.erase({u, v});
            egs.push_back({p.first, i - 1, u, v, p.second});
        } else {
            cin >> u >> v >> w; u--, v--;
            if(u > v) swap(u, v);

            for (int x : {u, v}) {
                S3.erase(S3.find(rs[x]));
                G[x].insert(w);
                rs[x] = get(x);
                S3.insert(rs[x]);
            }

            in[{u, v}] = {i, w};
        }
        res[i] = *S3.begin();
    }

//    rep(i, 0, q + 1) {
//        cout << i << ": " << res[i] << endl;
//    }

    for(auto &p : in) {
        egs.push_back({p.second.first, q,
                       p.first.first, p.first.second,
                       p.second.second});
    }

//    for (auto &e : egs) {
//        cout << e.u + 1 << " " << e.v + 1 << " [" << e.tl << " " << e.tr << "] " << e.w << endl;
//    }

    sort(all(egs), [](const Eg &e1, const Eg &e2) {
        return e1.w < e2.w;
    });


    rep(i, 0, 150) solve();

    rep(i, 0, q + 1) {
        cout << res[i] << endl;
    }




}