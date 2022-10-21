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
const int N = (int)5e5 + 50;
const ll INF = (ll)1e18;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

struct node {
    ll v0, v1, v2;
};

node merge(node L, node R) {
    return {max(L.v0, R.v0), max(L.v1, R.v1), max(L.v2, R.v2)};
}

struct Tree {
    node dat[4 * N];
    void init(int x, int l, int r) {
        if(l == r) {
            dat[x] = {-INF, -INF, -INF};
            return ;
        }
        int mid = (l + r) / 2;
        init(lson(x), l, mid);
        init(rson(x), mid + 1, r);
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r, node p) {
        if(l == r){
            dat[x].v0 = max(dat[x].v0, p.v0);
            dat[x].v1 = max(dat[x].v1, p.v1);
            dat[x].v2 = max(dat[x].v2, p.v2);
            return ;
        }
        int mid = (l + r) / 2;
        if(pos <= mid) update(pos, lson(x), l, mid, p);
        else update(pos, rson(x), mid + 1, r, p);
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r) {
        if(r < a || b < l) return {-INF, -INF, -INF};
        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];
        else return merge(query(a, b, lson(x), l, mid),
                          query(a, b, rson(x), mid + 1, r));
    }
} tree;

int n, a[N];
ll psum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        vector<ll> vs;
        rep(i, 1, n + 1) cin >> a[i], psum[i] = psum[i - 1] + a[i], vs.push_back(psum[i]);
        vs.push_back(0);
        sort(all(vs));
        vs.resize(unique(all(vs)) - vs.begin());
        int m = sz(vs);

        tree.init(0, 0, m - 1);
        auto getidx = [&](ll s) {
            return lower_bound(all(vs), s) - vs.begin();
        };
        tree.update(getidx(0), 0, 0, m - 1, {0, 0, 0});
        ll fres = 0;
        rep(i, 1, n + 1) {
            int idx = getidx(psum[i]);
            ll res = tree.query(0, idx - 1, 0, 0, m - 1).v0 + i;
            res = max(res, tree.query(idx, idx, 0, 0, m - 1).v1);
            res = max(res, tree.query(idx + 1, m - 1, 0, 0, m - 1).v2 - i);
            tree.update(idx, 0, 0, m - 1, {res - i, res, res + i});
            if(i == n) fres = res;
        }
        cout << fres << "\n";

    }
}