#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

const int N = (int)5e5 + 50;
const ll INF = (ll)1e18;

struct edge {
    int to, w;
};

struct Qr {
    int l, r, idx;
};

int n, q;
ll dep[N], tin[N], tout[N], tim = 0;
vector<edge> G[N];
ll res[N], off = 0;
vector<Qr> qrs[N];

void dfs(int v, ll d) {
    tin[v] = tim++;
    assert(tin[v] == v);
    for(auto &e : G[v]) {
        dfs(e.to, d + e.w);
    }
    dep[v] = G[v].empty() ? d : INF;
//    cout << v << " " << dep[v] << endl;
    tout[v] = tim - 1;
}

struct node {
    ll mn, add;

    void add_val(ll x) {
        mn += x;
        add += x;
    }

    void merge(node &ls, node &rs) {
        mn = min(ls.mn, rs.mn);
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].add) {
            if(l < r) {
                dat[ls(x)].add_val(dat[x].add);
                dat[rs(x)].add_val(dat[x].add);
            }
            dat[x].add = 0;
        }
    }

    void init(int x = 0, int l = 0, int r = n-1) {
        if(l == r) {
            dat[x].mn = dep[l];
            dat[x].add = 0;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].add = 0;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    ll query(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return INF;
        push_down(x, l, r);
        if(l >= a && r <= b) return dat[x].mn;
        return min(query(a, b, ls(x), l, mid), query(a, b, rs(x), mid+1, r));
    }

    void update(int a, int b, int x, int l, int r, ll delta) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].add_val(delta);
            return ;
        }
        update(a, b, ls(x), l, mid, delta);
        update(a, b, rs(x), mid+1, r, delta);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }
} tree;

void solve(int v) {
    for(auto qr : qrs[v]) {
        res[qr.idx] = tree.query(qr.l, qr.r, 0, 0, n - 1) + off;
    }
    for(auto &e : G[v]) {
        off += e.w;
        tree.update(tin[e.to], tout[e.to], 0, 0, n - 1, -2 * e.w);
        solve(e.to);
        off -= e.w;
        tree.update(tin[e.to], tout[e.to], 0, 0, n - 1, 2 * e.w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 1, n) {
        int p, w;
        cin >> p >> w; p--;
        G[p].push_back({i, w});
    }
    dfs(0, 0);
    tree.init(0, 0, n - 1);
    rep(i, 0, q) {
        int v, l, r; cin >> v >> l >> r; v--, l--, r--;
        qrs[v].push_back({l, r, i});
    }
    solve(0);
    rep(i, 0, q) cout << res[i] << '\n';
}