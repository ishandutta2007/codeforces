#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50, LOGN = 17;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

int n, a[N], k;
ll mod;
vi dvs;
ll pw[10][N * 17];


ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else {
        x = 1; y = 0;
    }
    return d;
}

ll ginv(ll v) {
    assert(__gcd(v, mod) == 1);
    ll x, y;
    extgcd(v, mod, x, y);
    return (x % mod + mod) % mod;
}

struct node {
    vi vs;
    ll remmul, mul, sum;


    void init(int val) {
        sum = val % mod;
        rep(i, 0, k) {
            while(val % dvs[i] == 0) val /= dvs[i], vs[i]++;
        }
        remmul = val % mod;
    }

    void add_val(vi &vals, ll rem, ll s) {
        sum = sum * s % mod;
        mul = mul * s % mod;

        remmul = remmul * rem % mod;
        rep(i, 0, sz(vs)) vs[i] += vals[i];
    }



    void del_val(vi &vals, ll rem) {
        remmul = remmul * ginv(rem) % mod;
        rep(i, 0, k) vs[i] -= vals[i];
        sum = remmul;
        rep(i, 0, k) sum = (sum * pw[i][vs[i]] % mod);
    }


    void merge(node &ls, node &rs) {
        sum = (ls.sum + rs.sum) % mod;
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(l < r) {
            dat[ls(x)].add_val(dat[x].vs, dat[x].remmul, dat[x].mul);
            dat[rs(x)].add_val(dat[x].vs, dat[x].remmul, dat[x].mul);
            fill(all(dat[x].vs), 0);
            dat[x].mul = 1;
            dat[x].remmul = 1;
        }
    }

    void init(int x, int l, int r) {
        dat[x].remmul = dat[x].mul = 1;
        dat[x].vs = vi(k, 0);
        if(l == r) {
            dat[x].init(a[l]);
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    ll qsum(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;

        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x].sum;

        return (qsum(a, b, ls(x), l, mid) + qsum(a, b, rs(x), mid+1, r)) % mod;
    }

    void range_mul(int a, int b, int x, int l, int r, vi &vs, ll rem, ll sum) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].add_val(vs, rem, sum);
            return ;
        }

        range_mul(a, b, ls(x), l, mid, vs, rem, sum);
        range_mul(a, b, rs(x), mid+1, r, vs, rem, sum);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    void point_div(int pos, int x, int l, int r, vi &vs, ll rem) {
        if(l == r) {
            dat[x].del_val(vs, rem);
            return ;
        }
        push_down(x, l, r);
        int mid = (l + r) / 2;
        if(pos <= mid) point_div(pos, ls(x), l, mid, vs, rem);
        else point_div(pos, rs(x), mid + 1, r, vs, rem);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }
} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> mod;
    int curx = mod;
    for(int i = 2; i * i <= curx; i++) {
        if(curx % i == 0) {
            dvs.push_back(i);
            while(curx % i == 0) {
                curx /= i;
            }
        }
    }
    if(curx > 1) dvs.push_back(curx);
    k = sz(dvs);

    rep(i, 0, k) {
        pw[i][0] = 1;
        rep(j, 1, N * 17) pw[i][j] = pw[i][j - 1] * dvs[i] % mod;
    }

    rep(i, 0, n) cin >> a[i];
    tree.init(0, 0, n - 1);

    int q;
    cin >> q;
    while(q--) {
        int tp; cin >> tp;
        if(tp == 1) {
            // multiply l to r by x
            int l, r, x;
            cin >> l >> r >> x; l--, r--;
            vi vs(k, 0);
            int cx = x;
            rep(i, 0, k) {
                while(cx % dvs[i] == 0) {
                    vs[i]++;
                    cx /= dvs[i];
                }
            }
            tree.range_mul(l, r, 0, 0, n - 1, vs, cx, x);
        } else if(tp == 2) {
            // divide p by x;
            int p, x;
            cin >> p >> x; p--;
            vi vs(k, 0);
            int cx = x;
            rep(i, 0, k) {
                while(cx % dvs[i] == 0) {
                    vs[i]++;
                    cx /= dvs[i];
                }
            }
            tree.point_div(p, 0, 0, n - 1, vs, cx);
        } else {
            // sum l to r
            int l, r;
            cin >> l >> r; l--, r--;
            cout << tree.qsum(l, r, 0, 0, n - 1) << '\n';
        }
    }

}