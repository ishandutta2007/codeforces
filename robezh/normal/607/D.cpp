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

const int N = (int)2e5 + 50;

const int MOD = (int)1e9 + 7;

struct mi {
    typedef decay<decltype(MOD)>::type T;
    /// don't silently convert to T
    T v; explicit operator T() const { return v; }
    mi() { v = 0; }
    mi(ll _v) {
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mi& a, const mi& b) {
        return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) {
        return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) {
        return a.v < b.v; }
//    friend void re(mi& a) { ll x; re(x); a = mi(x); }
//    friend str ts(mi a) { return ts(a.v); }

    mi& operator+=(const mi& m) {
        if ((v += m.v) >= MOD) v -= MOD;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((v -= m.v) < 0) v += MOD;
        return *this; }
    mi& operator*=(const mi& m) {
        v = (ll)v*m.v%MOD; return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mi inv(const mi& a) { assert(a.v != 0);
        return pow(a,MOD-2); }

    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

struct node {
    mi sum, mul;

    void add_val(mi x) {
        sum *= x;
        mul *= x;
    }

    void merge(node &ls, node &rs) {
        sum = ls.sum + rs.sum;
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].mul != 1) {
            if(l < r) {
                dat[ls(x)].add_val(dat[x].mul);
                dat[rs(x)].add_val(dat[x].mul);
            }
            dat[x].mul = 1;
        }
    }

    void init(int x, int l, int r, int val) {
        if(l == r) {
            dat[x] = {val, 1};
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid, val);
        init(rs(x), mid + 1, r, val);
        dat[x].mul = 1;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    mi qsum(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;
        push_down(x, l, r);
        if(l >= a && r <= b) return dat[x].sum;
        return qsum(a, b, ls(x), l, mid) + qsum(a, b, rs(x), mid+1, r);
    }

    void update(int a, int b, int x, int l, int r, mi val) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].add_val(val);
            return ;
        }
        update(a, b, ls(x), l, mid, val);
        update(a, b, rs(x), mid+1, r, val);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    void pointset(int pos, int x, int l, int r, mi val) {
        int mid = (l + r) / 2;
        push_down(x, l, r);
        if(l == r) {
            dat[x].sum = val;
            return ;
        }
        if(pos <= mid) pointset(pos, ls(x), l, mid, val);
        else pointset(pos, rs(x), mid + 1, r, val);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

} tree[2];


struct Qr {
    int tp, v, p, val;
} qr[N];



int par[N], tin[N], tout[N], tim = 0;
int n, q;
vi G[N];
int vs[N];
int in_cnt[N];

void dfs(int v, int p) {
    tin[v] = tim++;
    par[v] = p;
    for (int nxt : G[v]) {
        dfs(nxt, v);
    }
    tout[v] = tim - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> vs[0] >> q;
    n = 1;
    rep(i, 0, q) {
        int tp;
        cin >> tp;
        if(tp == 1) {
            int p, val; cin >> p >> val; p--;
            G[p].push_back(n);
            vs[n] = val;
            qr[i] = {tp, n, p, val};
            n++;
        } else {
            int vt; cin >> vt; vt--;
            qr[i] = {tp, vt};
        }
    }
    dfs(0, -1);
    tree[0].init(0, 0, n - 1, 1);
    tree[1].init(0, 0, n - 1, 0);
//    tree[0].update(tin[0], tout[0], 0, 0, n - 1, 1);
    tree[1].pointset(tin[0], 0, 0, n - 1, vs[0]);

    rep(i, 0, q) {
        if(qr[i].tp == 1) {
            int p = qr[i].p, v = qr[i].v;
            mi r = mi(in_cnt[p] + 2) / mi(in_cnt[p] + 1);
            tree[0].update(tin[p], tout[p], 0, 0, n - 1, r);

            tree[1].update(tin[p], tout[p], 0, 0, n - 1,r);

//            cout << "set: " << int(tree[0].qsum(tin[p], tin[p], 0, 0, n - 1) * qr[i].val) << endl;
            tree[1].pointset(tin[v], 0, 0, n - 1,
                             tree[0].qsum(tin[p], tin[p], 0, 0, n - 1) * qr[i].val);
            in_cnt[p]++;
        } else {
            int v = qr[i].v;

            mi res = tree[1].qsum(tin[v], tout[v], 0, 0, n - 1);
            int p = par[v];
//            cout << (int)res << endl;
//            cout << "div: " << (int)(tree[0].qsum(tin[p], tin[p], 0, 0, n - 1)) << endl;
            if(p != -1) res *= inv(tree[0].qsum(tin[p], tin[p], 0, 0, n - 1));
            cout << int(res) << endl;
        }
    }

}