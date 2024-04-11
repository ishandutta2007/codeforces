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
typedef vector<int> vi;
#define lson(x) 2*x+1
#define rson(x) 2*x+2

const int N = (int)2e5 + 50, INF = (int)1e9 + 50;

struct edge {
    int to, id;
};

int n, m;
vector<edge> G[N];
int low[N], pre[N];
int ccnt = 0;
vector<int> bcc[N];
int cut[N];
int in[N];
int comp[N], rc[N];
stack<int> S;
int cnt = 0, rcnt = 0;
pii p[N];
vector<int> H[N];

void dfs(int v, int par) {
    low[v] = pre[v] = ++cnt;

    int childcnt = 0;
    for(int j = 0; j < G[v].size(); j++) {
        edge e = G[v][j];
        if(e.to == par) continue;
        if(!pre[e.to]) {
            S.push(e.id);
            childcnt++;
            dfs(e.to, v);
            low[v] = min(low[v], low[e.to]);
            if(low[e.to] >= pre[v]) {
                cut[v] = true;
                int cur;
                do {
                    cur = S.top();
                    S.pop();
                    bcc[ccnt].push_back(p[cur].first);
                    bcc[ccnt].push_back(p[cur].second);
                } while(cur != e.id);
                ccnt++;
            }
        }
        else if(pre[e.to] < pre[v]){
            S.push(e.id);
            low[v] = min(low[v], pre[e.to]);
        }
    }

    if(childcnt < 2 && par == -1) cut[v] = false;

}

int chainNo, top[N], dfn[N], totsize, ord[N], dep[N];
int subsize[N], par[N];

multiset<int> vs[N];

struct SegTree {
    int dat[N * 4];

    void init_dat(int x, int l, int r){
        if(l == r) {
            int v = ord[l];
            dat[x] = (vs[v].empty() ? INF : *vs[v].begin());
//            cout << v << ": " << dat[x] << endl;
            return;
        }

        int mid = (l + r) / 2;
        init_dat(lson(x), l, mid);
        init_dat(rson(x), mid+1, r);
        dat[x] = min(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = val;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        dat[x] = min(dat[lson(x)], dat[rson(x)]);
    }

    int query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return INF;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];
        return min(query(a, b, lson(x), l, mid), query(a, b, rson(x), mid+1, r));
    }

} tree;



struct HLD {
    int n;

    void dfs(int v, int p, int d){
        par[v] = p;
        subsize[v] = 1;
        dep[v] = d;
        for(int &nxt : H[v]){
            if(nxt == p) continue;
            dfs(nxt, v, d+1);
            subsize[v] += subsize[nxt];
            if(H[v][0] == p || subsize[nxt] > subsize[H[v][0]])
                swap(nxt, H[v][0]);
        }
    }

    void hld(int v, int p, int tp){

        top[v] = tp;
        dfn[v] = totsize;
        ord[totsize++] = v;

        for(auto nxt : H[v]){
            if(nxt == p) continue;
            if(nxt != H[v][0]) {
                chainNo ++;
                hld(nxt, v, nxt);
            } else {
                hld(nxt, v, tp);
            }
        }
    }


    void init_hld(int V, int tx){
        n = V;
        chainNo = totsize = 0;
        fill(dfn, dfn + n, -1);
        rep(i, tx, n) {
            if(dfn[i] == -1) {
                dfs(i, -1, 0);
                hld(i, -1, i);
            }
        }
    }

    void init_tree() {
        tree.init_dat(0, 0, n - 1);
    }

    void update(int v, int val) {
        tree.update(dfn[v], 0, 0, n - 1, val);
    }
} hld;
int q;
int w[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    rep(i, 0, n) cin >> w[i];
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
        p[i] = {a, b};
    }
    for(int i = 0; i < n; i++) {
        if(!pre[i]) {
            dfs(i, -1);
        }
    }


    rcnt = n + ccnt;
    rep(i, 0, ccnt) {
        sort(all(bcc[i]));
        bcc[i].resize(unique(all(bcc[i])) - bcc[i].begin());
        for (int x : bcc[i]) {
            H[i + n].push_back(x);
            H[x].push_back(i + n);
//            cout << i + n << " to " << x << endl;
        }
//        cout << endl;
    }


//    cout << ccnt << " " << rcnt << endl;
//    rep(i, 0, n) {
//        vs[comp[i]].insert(w[i]);
//        cout << i + 1 << " " << comp[i] << " in: " << in[i]<< " " << w[i] << endl;
//    }
//    rep(i, 0, ccnt) {
//        cout << i << ": " << (vs[i].empty() ? INF : *vs[i].begin()) << endl;
//    }
    hld.init_hld(rcnt, n);
    rep(i, 0, n) {
//        cout << "par " << i << " " << par[i] << endl;
        if(par[i] != -1) {
            vs[par[i]].insert(w[i]);
        }
        vs[i].insert(w[i]);
    }
    hld.init_tree();


    while(q--) {
        char c; int a, b;
        cin >> c >> a >> b;
        if(c == 'C') {
            a--;
            assert(par[a] != -1);
            vs[par[a]].erase(vs[par[a]].find(w[a]));
            vs[a].erase(vs[a].find(w[a]));

            w[a] = b;

            vs[a].insert(w[a]);
            vs[par[a]].insert(w[a]);

//                cout << "update " << a << " " << rc[a] << *vs[par[a]].begin() << endl;
            hld.update(par[a], *vs[par[a]].begin());
            hld.update(a, *vs[a].begin());
        } else {
            a--, b--;
            if(a == b) {
                cout << w[a] << '\n';
                continue;
            }
            int res = INF;
            while(top[a] != top[b]) {
//                cout << a << " " << b << endl;
                if(dep[top[a]] < dep[top[b]]) swap(a, b);
                res = min(res, tree.query(dfn[top[a]], dfn[a], 0, 0, hld.n - 1));
                a = par[top[a]];
            }
            if(dfn[a] > dfn[b]) swap(a, b);
            res = min(res, tree.query(dfn[a], dfn[b], 0, 0, hld.n - 1));
//            cout << a << " " << b << " par " << par[a] << endl;
            if(par[a] >= 0 && par[a] < n) res = min(res, w[par[a]]);
            cout << res << '\n';
//            cout << hld.query(a, b) << '\n';
        }
    }


}