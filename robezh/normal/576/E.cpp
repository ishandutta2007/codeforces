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

const int N = (int)5e5 + 50;

vector<pii> upd[4 * N];

class DSU {
public:
    int n;
    int bad = 0;
    int f[50 *  N], sz[50 * N], c[50 * N];
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

    bool good(int u, int v) {
        auto x = findhead(u), y = findhead(v);
//        cout << sz(stk) << " " << x.first << " " << y.first << " " << x.second << " " << y.second << endl;
        return x.first != y.first || (x.second ^ y.second) != 0;
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




int n, m, q, k;
pii es[N];
struct Qr {
    int eid, c;
} qr[N];
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

int col[N];
int nxt[N], las[N];

void calc(int x, int l, int r) {
    int stk_size = sz(dsu.stk);
    for (auto p : upd[x]) {
        dsu.add_edge(p.first, p.second);
    }
    if(l == r) {
        if(r + 1 < q) {
            int c = qr[r + 1].c;
            int u = es[qr[r + 1].eid].first, v = es[qr[r + 1].eid].second;
            int &oc = col[qr[r + 1].eid];
//            cout << "at " << l << " " << r << endl;
            res[r + 1] = dsu.good(u + c * n, v + c * n);
            if(res[r + 1]) oc = c;
            if(oc != -1)  {

                add_upd(r + 1, nxt[r + 1] - 1, 0, 0, q - 1, pii{u + oc * n, v + oc * n});
//                cout << r + 1 << " " << nxt[r + 1] - 1 << endl;
            }
        }


    } else {
        int mid = (l + r) / 2;
        calc(lson(x), l, mid);
        calc(rson(x), mid + 1, r);
    }
    while(sz(dsu.stk) > stk_size) dsu.pop_edge();
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k >> q;
    dsu.init(k * n);

    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        es[i] = {u, v};
    }
    for (int i = 0; i < q; i++) {
        int id, c; cin >> id >> c; id--, c--;
        qr[i] = {id, c};
    }

    fill(las, las + N, q);
    for (int i = q - 1; i >= 0; i--) {
        nxt[i] = las[qr[i].eid];
        las[qr[i].eid] = i;
    }

    fill(col, col + m, -1);
    add_upd(0, nxt[0] - 1, 0, 0, q - 1,
            {es[qr[0].eid].first + qr[0].c * n, es[qr[0].eid].second + qr[0].c * n});
    col[qr[0].eid] = qr[0].c;
//    cout << 0 << " " << nxt[0] - 1 << endl;
    res[0] = 1;
    calc(0, 0, q - 1);

    rep(i, 0, q) cout << (res[i] ? "YES" : "NO") << '\n';



}