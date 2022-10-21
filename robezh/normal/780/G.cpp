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
const int N = (int)3e5 + 50;
const int mod = (int)1e9 + 7;
const int INF = (int)2e9;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

struct node {
    int cnt;
    pii mn;
};

node none = {0, {INF, -1}};

node merge(node L, node R) {
    return {(L.cnt + R.cnt) % mod, min(L.mn, R.mn)};
}

vector<pii> ps;
int h, w, n;

struct Tree {
    node dat[4 * N];
    void init(int x, int l, int r) {
        if(l == r) {
            dat[x] = ps[l].second == -1 ? node{1, {h + 1, l}} : none;
            return ;
        }
        int mid = (l + r) / 2;
        init(lson(x), l, mid);
        init(rson(x), mid + 1, r);
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r, node v) {
        if(l == r) {
            dat[x] = v;
            return ;
        }
        int mid = (l + r) / 2;
        if(pos <= mid) update(pos, lson(x), l, mid, v);
        else update(pos, rson(x), mid + 1, r, v);
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
    }

    int find_under(int a, int b, int x, int l, int r, int val) {
        if(r < a || b < l) return 0;
        int mid = (l + r) / 2;
        if(dat[x].mn.first > val) return 0;
        if(l == r) {
            int res = dat[x].cnt;
            dat[x] = none;
            return res;
        }
        int L = find_under(a, b, lson(x), l, mid, val);
        int R = find_under(a, b, rson(x), mid + 1, r, val);
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
        return (L + R) % mod;
    }

    node query(int a, int b, int x, int l, int r) {
        if(r < a || b < l) return none;
        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];
        else return merge(query(a, b, lson(x), l, mid),
                          query(a, b, rson(x), mid + 1, r));
    }
} tree;

int u[N], l[N], r[N], s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w >> n;
    rep(i, 0, w) ps.push_back({i, -1});
    rep(i, 0, n) {
        cin >> u[i] >> l[i] >> r[i] >> s[i];
        l[i]--, r[i]--;
        if(r[i] + 1 < w) ps.push_back({r[i] + 1, i});
        if(l[i]) ps.push_back({l[i] - 1, i});
    }
    sort(all(ps));
    tree.init(0, 0, sz(ps) - 1);
    vi idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](const int i, const int j) {
        return u[i] > u[j];
    });
    for (int i : idx) {
        int lb = lower_bound(all(ps), pii{l[i], -INF}) - ps.begin();
        int rb = lower_bound(all(ps), pii{r[i] + 1, -INF}) - ps.begin() - 1;
        int cnt = tree.find_under(lb, rb, 0, 0, sz(ps) - 1, u[i] + s[i]);
//        cout << "catching " << cnt << endl;
//        cout << tree.dat[0].cnt << endl;
        int lidx = (l[i] == 0 ? -1 : lower_bound(all(ps), pii{l[i] - 1, i}) - ps.begin());
        int ridx = (r[i] == w - 1 ? -1 : lower_bound(all(ps), pii{r[i] + 1, i}) - ps.begin());
//        cout << lidx << " " << ridx << endl;
        if(lidx == -1) {
            tree.update(ridx, 0, 0, sz(ps) - 1, node{cnt * 2 % mod, {u[i], ridx}});
        } else if(ridx == -1) {
            tree.update(lidx, 0, 0, sz(ps) - 1, node{cnt * 2 % mod, {u[i], lidx}});
        } else {
            tree.update(lidx, 0, 0, sz(ps) - 1, node{cnt, {u[i], lidx}});
            tree.update(ridx, 0, 0, sz(ps) - 1, node{cnt, {u[i], ridx}});
        }
    }
    cout << tree.dat[0].cnt << '\n';
}