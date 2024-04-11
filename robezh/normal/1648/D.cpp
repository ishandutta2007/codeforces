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
typedef pair<int, int> P;

const int N = (int)5e5 + 50;
const ll INF = (ll)1e18;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2


struct node {
    ll mx, mx2, res;

    void merge(node &ls, node &rs) {
        mx = max(ls.mx, rs.mx);
        mx2 = max(ls.mx2, rs.mx2);
        res = max(max(rs.res, ls.res), ls.mx + rs.mx2);
    }
};

struct Tree {
    node dat[4 * N];

    void init(int n) {
        fill(dat, dat + 4 * n, node{-INF, -INF});
    }

    node query(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return {-INF, -INF, -INF};

        if(l >= a && r <= b) return dat[x];
        node L = query(a, b, ls(x), l, mid);
        node R = query(a, b, rs(x), mid+1, r);
        node res;
        res.merge(L, R);
        return res;
    }

    void update(int pos, int x, int l, int r, node v) {
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = v;
            return ;
        }
        if(pos <= mid) update(pos, ls(x), l, mid, v);
        else update(pos, rs(x), mid + 1, r, v);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

} tree;


struct Seg {
    int l, r, k;
};

int n, q;
int a[4][N];
ll s[4][N];
vector<pii> from[N];
vector<Seg> segs;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 1, 4) rep(j, 1, n + 1) {
        cin >> a[i][j];
        s[i][j] = a[i][j] + s[i][j - 1];
    }

    rep(i, 0, q) {
        int l, r, k; cin >> l >> r >> k;
        from[r + 1].push_back({l, k});
        segs.push_back({l, r, k});
    }

    tree.init(n + 1);
    for (int i = 1; i <= n; i++) {
        ll mx = s[1][i] - s[2][i - 1];
        for (auto &p : from[i]) {
            mx = max(mx, tree.query(p.first, i - 1, 0, 0, n).mx - p.second);
        }
        node nd = {mx, (s[2][i] - s[3][i - 1]) + s[3][n], mx + (s[2][i] - s[3][i - 1]) + s[3][n]};
        tree.update(i, 0, 0, n, nd);
    }

    ll res = -INF;
    for (auto &e : segs) {
        res = max(res, tree.query(e.l, e.r, 0, 0, n).res - e.k);
    }

    cout << res << '\n';

}