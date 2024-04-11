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

const int N = (int)1e5 + 50, B = 1002;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

//ll tsum[10];


int m;
int xs[N];
vi G[N];
int tin[N], tout[N], ord[N], tim;
vi pm;
bool isp[B];
bitset<B> sub;


struct node {
    int add;
    bitset<B> bs;

    void init(int val) {
        bs.reset();
        bs[val % m] = true;
    }

    void add_val(int v) {
        add += v;
        v %= m;
        bs = ((bs << v) | (bs >> (m - v))) & sub;
    }

    void merge(node &ls, node &rs) {
        bs = ls.bs | rs.bs;
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
            dat[x].init(xs[ord[l]]);
            dat[x].add = 0;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].add = 0;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    bitset<B> query(int a, int b, int x = 0, int l = 0, int r = N-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return bitset<B>();

        push_down(x, l, r);

        if(l >= a && r <= b) {
            return dat[x].bs;
        }

        return query(a, b, ls(x), l, mid) | query(a, b, rs(x), mid+1, r);
    }

    void update(int a, int b, int x, int l, int r, int v) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].add_val(v);
            return ;
        }

        update(a, b, ls(x), l, mid, v);
        update(a, b, rs(x), mid+1, r, v);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }
} tree;

void dfs(int v, int p) {
    ord[tim] = v;
    tin[v] = tim++;
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
    }

    tout[v] = tim - 1;
}

int n, q;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;

    fill(isp, isp + m + 1, 1);
    for (int i = 2; i <= m; i++) {
        if(isp[i]) {
            pm.push_back(i);
            for (int j = i * 2; j <= m; j += i) isp[j] = false;
        }
    }
    rep(i, 0, m) sub[i] = 1;
//    for (int x : pm) cout << x << " ";;
//    cout << endl;

    rep(i, 0, n) cin >> xs[i];
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    tree.init(0, 0, n - 1);
    cin >> q;
    while(q--) {
        int tp, v; cin >> tp >> v; v--;
        if(tp == 1) {
            int x; cin >> x; x %= m;
            tree.update(tin[v], tout[v], 0, 0, n - 1, x);
        } else {
            auto res = tree.query(tin[v], tout[v], 0, 0, n - 1);
            int cnt = 0;
            for (int x : pm) {
                cnt += res[x];
//                if(res[x]) cout << x << " ";
            }
//            cout << endl;
            cout << cnt << '\n';
        }
    }

}