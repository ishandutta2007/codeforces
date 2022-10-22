#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const int MAXN = 5e5 + 7;
const double EPS = 1e-6;

vector <vector <pair <ll, ll> > > gr;

vector <ll> lt, rt, d;

void dfs(ll v, ll wt = 0) {
    d[v] = wt;
    lt[v] = v;
    rt[v] = v;
    for (auto e : gr[v]) {
        ll u = e.first, w = e.second;
        dfs(u, wt + w);
        lt[v] = min(lt[v], lt[u]);
        rt[v] = max(rt[v], rt[u]);
    }
}

ll n, q;

struct Tree {
    vector <ll> t, valt;
    Tree() : t(4 * n, 0), valt(4 * n, 0) {}
    void relax(ll v) {
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
    void add_val(ll v, ll val) {
        t[v] += val;
        valt[v] += val;
    }
    void push(ll v) {
        add_val(2 * v, valt[v]);
        add_val(2 * v + 1, valt[v]);
        valt[v] = 0;
    }
    void add_seg(ll l, ll r, ll val, ll lt = 0, ll rt = n, ll v = 1) {
        if (lt >= r || l >= rt) {
            return;
        }
        if (l <= lt && rt <= r) {
            add_val(v, val);
            return;
        }
        push(v);
        ll mt = (lt + rt) / 2;
        add_seg(l, r, val, lt, mt, 2 * v);
        add_seg(l, r, val, mt, rt, 2 * v + 1);
        relax(v);
    }
    ll get(ll l, ll r, ll lt = 0, ll rt = n, ll v = 1) {
        if (lt >= r || l >= rt) {
            return INF;
        }
        if (l <= lt && rt <= r) {
            return t[v];
        }
        push(v);
        ll mt = (lt + rt) / 2;
        ll res = min(get(l, r, lt, mt, 2 * v), get(l, r, mt, rt, 2 * v + 1));
        relax(v);
        return res;
    }
};

Tree t;

struct Query {
    ll l, r, id;
};

vector <ll> res;

vector <Query> qs[MAXN];

void dfs1(ll v) {
//    cout << v << "\n";
//    for (ll i = 0; i < n; i++) {
//        cout << t.get(i, i + 1) << " ";
//    }
//    cout << "\n";
    for (auto tt : qs[v]) {
        res[tt.id] = t.get(tt.l, tt.r + 1);
    }
    for (auto e : gr[v]) {
        ll u = e.first, w = e.second;
        ll l = lt[u], r = rt[u];
        t.add_seg(0, l, w);
        t.add_seg(l, r + 1, -w);
        t.add_seg(r + 1, n, w);
        dfs1(u);
        t.add_seg(0, l, -w);
        t.add_seg(l, r + 1, w);
        t.add_seg(r + 1, n, -w);
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
    cin >> n >> q;
    gr.resize(n);
    lt.resize(n);
    rt.resize(n);
    d.resize(n);
    for (ll i = 1; i < n; i++) {
        ll p, w;
        cin >> p >> w;
        p--;
        gr[p].push_back({i, w});
    }
    dfs(0);
    t = Tree();
    for (ll i = 0; i < n; i++) {
        if (gr[i].size()) {
            t.add_seg(i, i + 1, INF);
            //cout << INF << " ";
        } else {
            t.add_seg(i, i + 1, d[i]);
            //cout << d[i] << " ";
        }
    }
    //cout << "\n";
//    for (ll i = 0; i < n; i++) {
//        cout << t.get(i, i + 1) << " ";
//    }
//    cout << "\n";
    for (ll i = 0; i < q; i++) {
        ll v, l, r;
        cin >> v >> l >> r;
        v--, l--, r--;
        qs[v].push_back({l, r, i});
    }
    res.resize(q);
    dfs1(0);
    for (auto x : res) {
        cout << x << "\n";
    }
}