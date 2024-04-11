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

const int N = (int)2e5 + 50;

vector<pii> upd[4 * N];

class DSU {
public:
    int n;
    int f[N], sz[N];
    stack<pii> stk;

    void init(int _n) {
        n = _n;
        rep(i, 0, n) {
            f[i] = i;
            sz[i] = 1;
        }
    }

    int findhead(int x) {
        return f[x] == x ? x : findhead(f[x]);
    }

    bool same(int x, int y) {
        return findhead(x) == findhead(y);
    }

    void add_edge(int u, int v) {
        auto x = findhead(u), y = findhead(v);
        if(sz[x] > sz[y]) swap(x,y);
        if(x == y) return ;

        stk.push({x, y});
        f[x] = y;
        sz[y] += sz[x];
    }

    void pop_edge() {
        int x = stk.top().first, y = stk.top().second; stk.pop();
        assert(x != y);
        f[x] = x;
        sz[y] -= sz[x];
    }
} dsu;




int n, q;
struct Qr {
    int tp, u, v;
} qr[N];
int res[N];

map<pii, int> in;

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

int nxt[N][2];

void calc(int x, int l, int r) {
    int stk_size = sz(dsu.stk);
    for (auto p : upd[x]) {
        dsu.add_edge(p.first, p.second);
    }
    if(l == r) {
        if(r + 1 < q) {
            if(qr[r + 1].tp == 1) {
                rep(last, 0, 2) {
                    int u = (qr[r + 1].u + last) % n, v = (qr[r + 1].v + last) % n;
                    if(u > v) swap(u, v);
                    if(last == res[r]) in[{u, v}] ^= 1;
                }
                rep(last, 0, 2) {
                    int u = (qr[r + 1].u + last) % n, v = (qr[r + 1].v + last) % n;
                    if(u > v) swap(u, v);
                    if(in[{u, v}]) {
                        add_upd(r + 1, nxt[r + 1][last] - 1, 0, 0, q - 1, {u, v});
                    }
                }
                res[r + 1] = res[r];
            } else {
                int u = (qr[r + 1].u + res[r]) % n, v = (qr[r + 1].v + res[r]) % n;
                if(u > v) swap(u, v);
                res[r + 1] = dsu.same(u, v);
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

    cin >> n >> q;
    dsu.init(n);

    for (int i = 0; i < q; i++) {
        int tp, x, y;
        cin >> tp >> x >> y; x--, y--;
        if(x > y) swap(x, y);
        qr[i] = {tp, x, y};
    }

    map<pii, int> las;
    for (int i = q - 1; i >= 0; i--) {
        if(qr[i].tp == 2) continue;
        rep(last, 0, 2) {
            int u = (qr[i].u + last) % n, v = (qr[i].v + last) % n;
            if(u > v) swap(u, v);
            auto it = las.find({u, v});
            nxt[i][last] = (it == las.end()) ? q : it -> second;
            las[{u, v}] = i;
        }
    }


    if(qr[0].tp == 1) {
        add_upd(0, nxt[0][0] - 1, 0, 0, q - 1,
                {qr[0].u, qr[0].v});
        in[{qr[0].u, qr[0].v}] = 1;
    } else {
        res[0] = 0;
    }

    calc(0, 0, q - 1);

    rep(i, 0, q) {
        if(qr[i].tp == 2) cout << res[i];
    }
    cout << '\n';


}