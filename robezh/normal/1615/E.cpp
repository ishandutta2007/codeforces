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
const int N = (int)2e5 + 50, INF = (int)1e9 + 50;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

int n, k;

vector<int> G[N];
int lf[N];
int val[N], ord[N];
int rem = 0;
int par[N], in[N], out[N], tim;
int has[N];

struct node {
    pii mx;
    int add;

    void add_val(int x) {
        mx.first += x;
        add += x;
    }

    void merge(node &ls, node &rs) {
        mx = max(ls.mx, rs.mx);
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

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x].mx = {lf[ord[l]] ? val[l] : -INF, l};
//            cout << l << " " << val[l] << endl;
            dat[x].add = 0;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].add = 0;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    void update(int a, int b, int x, int l, int r, int delta) {
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


int lfcnt = 0;

void dfs(int v, int p, int d) {
    val[tim] = d;
    ord[tim] = v;
    in[v] = tim++;
    lf[v] = true;

    par[v] = p;
    for (int nxt : G[v]) {
        if(nxt != p) {
            dfs(nxt, v, d + 1);
            lf[v] = false;
        }
    }


    lfcnt += lf[v];
    out[v] = tim - 1;
//    cout << v << " " << in[v] << " " << out[v] << endl;
}


ll eval(ll r, ll rem) {
    ll b = rem * 2 >= n ? n / 2 : rem;
    return (n - r - b) * (r - b);
}

void update(int v) {
    do {
        has[v] = false;
        rem--;
//        cout << v << " " << in[v] << " " << out[v] << " " << -1 << endl;
        tree.update(in[v], out[v], 0, 0, n - 1, -1);
        v = par[v];
    } while(v != -1 && has[v]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1, 1);
    tree.init(0, 0, n - 1);

    fill(has, has + n, 1);
    ll res = eval(0, n);
    rem = n;
    rep(i, 1, k + 1) {
        if(lfcnt) {
            auto p = tree.dat[0].mx;
            update(ord[p.second]);
            lfcnt--;
//            cout << i << " choose " << " " << ord[p.second] << " " << rem << endl;
        }
        res = max(res, eval(i, rem));
    }
    cout << res << "\n";

}