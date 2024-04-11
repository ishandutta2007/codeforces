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

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2
const int N = (int)1e5 + 50;
//const ll INF = (int)

struct node {
    ll a0, sum0, len, mnd;

    void set(ll v) {
        sum0 = v;
        len = 1;
        mnd = v;
    }

    void add_val(ll d0) {
        mnd += d0;
        a0 += d0;
        sum0 += d0 * len;
    }

    void merge(node &ls, node &rs) {
        sum0 = ls.sum0 + rs.sum0;
        mnd = min(ls.mnd, rs.mnd);
        len = ls.len + rs.len;
    }
};

int n, m;
ll a[N], b[N];

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].a0) {
            if(l < r) {
                dat[ls(x)].add_val(dat[x].a0);
                dat[rs(x)].add_val(dat[x].a0);
            }
            dat[x].a0 = 0;
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x].set(b[l] - b[l - 1]);
            dat[x].a0 = 0;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].a0 = 0;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    ll qsum(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;

        push_down(x, l, r);
        if(l >= a && r <= b) return dat[x].sum0;
        return qsum(a, b, ls(x), l, mid) + qsum(a, b, rs(x), mid+1, r);
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


    int find(int x, int l, int r, ll val) {
        if(l == r) return l;
        int mid = (l + r) / 2;
        push_down(x, l, r);

        if(dat[rs(x)].mnd <= val) return find(rs(x), mid + 1, r, val);
        else return find(ls(x), l, mid, val);
    }
} tree;

int q;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    ll bsum = 0;
    rep(i, 1, n + 1) cin >> a[i];
    rep(j, 1, m + 1) cin >> b[j], bsum += b[j];
    tree.init(1, 1, m);
    rep(it, 0, q) {
        int tp, k;
        ll d;
        cin >> tp >> k >> d;
        if(tp == 1) for (int i = n - k + 1; i <= n; i++) a[i] += d * (i - (n - k));
        else {
            tree.update(m - k + 1, m, 1, 1, m, d);
            bsum += d * (k + 1) * k / 2;
        }
        int y = 1;
        ll res = bsum;
        rep(i, 1, n + 1) {
            int pos = (i == n ? m : max(y, tree.find(1, 1, m, a[i + 1] - a[i])));
            res += a[i] * (pos - y + 1);
            if(i > 1) res += tree.qsum(1, y, 1, 1, m);
            y = pos;
        }
        cout << res << '\n';
    }
}