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

const int N = (int)1e5 + 50, D = 10;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

//ll tsum[10];


int xs[N];

struct node {
    bool add;
    int to[10];
    ll sum[10];

    void init(int val) {
        rep(i, 0, D) sum[i] = 0;
        vi ds;
        while(val) ds.push_back(val % 10), val /= 10;
        reverse(all(ds));
        for (int v : ds) {
            rep(i, 0, D) sum[i] *= 10;
            sum[v]++;
        }
    }

    void add_val(int *ad) {
        add = true;
        ll tsum[10];
        fill(tsum, tsum + D, 0);
        rep(i, 0, D) tsum[ad[i]] += sum[i];
        copy(tsum, tsum + D, sum);
        rep(i, 0, D) to[i] = ad[to[i]];
    }

    void merge(node &ls, node &rs) {
        rep(i, 0, D) sum[i] = ls.sum[i] + rs.sum[i];
    }

};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].add) {
            if(l < r) {
                dat[ls(x)].add_val(dat[x].to);
                dat[rs(x)].add_val(dat[x].to);
            }
            dat[x].add = false;
            iota(dat[x].to, dat[x].to + D, 0);
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x].init(xs[l]);
            iota(dat[x].to, dat[x].to + D, 0);
            dat[x].add = false;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].add = false;
        iota(dat[x].to, dat[x].to + D, 0);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    ll query(int a, int b, int x = 0, int l = 0, int r = N-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            ll res = 0;
            rep(i, 0, D) res += dat[x].sum[i] * i;
            return res;
        }

        return query(a, b, ls(x), l, mid) + query(a, b, rs(x), mid+1, r);
    }

    void update(int a, int b, int x, int l, int r, int *ad) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].add_val(ad);
            return ;
        }

        update(a, b, ls(x), l, mid, ad);
        update(a, b, rs(x), mid+1, r, ad);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }
} tree;

int n, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n) cin >> xs[i];
    tree.init(0, 0, n - 1);
    rep(i, 0, q) {
        int tp, l, r;
        cin >> tp >> l >> r; l--, r--;
        if(tp == 1) {
            int x, y; cin >> x >> y;
            int ad[D];
            iota(ad, ad + D, 0);
            ad[x] = y;
            tree.update(l, r, 0, 0, n - 1, ad);
        } else {
            cout << tree.query(l, r, 0, 0, n - 1) << '\n';
        }
    }

}