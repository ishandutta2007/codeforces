#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what_is(x) cerr << #x << " is " << x << endl;
const int MOD = (int)1e9 + 9;

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

const int N = (int)1e5 + 50;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
typedef array<int,2> T; // bases not too close to ends
uniform_int_distribution<int> BDIST(0.1*MOD,0.9*MOD);
const T base = {BDIST(rng),BDIST(rng)};
//const T base = {10, 10};
const T ibase = {(int)inv(mi(base[0])),(int)inv(mi(base[1]))};
T operator+(T l, T r) {
    rep(i,0,2) if ((l[i] += r[i]) >= MOD) l[i] -= MOD;
    return l; }
T operator-(T l, T r) {
    rep(i,0,2) if ((l[i] -= r[i]) < 0) l[i] += MOD;
    return l; }
T operator*(T l, T r) {
    rep(i,0,2) l[i] = (ll)l[i]*r[i]%MOD;
    return l; }
vector<T> pows = {{1,1}}, ipows = {{1,1}};

ostream& operator<<(ostream& os, const T& dt) {
    os << "(" << dt[0] << ", " << dt[1] << ")";
    return os;
}

struct node {
    bool ok;
    int plen, slen;
    T pval, sval;
} d[4 * N];
ostream& operator<<(ostream& os, const node& dt) {
    os << "(" << dt.ok << ", " << dt.plen << ", " << dt.slen << ", " << dt.pval << ", " << dt.sval << ")";
    return os;
}

#define lc(x) 2*x+1
#define rc(x) 2*x+2

T get_prefix(int i, int len) {
    if(len == 0) return {0, 0};
    if(len == d[i].plen) return d[i].pval;
    int l = lc(i), r = rc(i);
    if(len <= d[l].plen) {
        return get_prefix(l, len);
    } else {
        return d[l].pval + (get_prefix(r, len - d[l].plen + d[l].slen) - d[l].sval)
            * ipows[d[l].slen] * pows[d[l].plen];
    }
}

T get_suffix(int i, int len) {
    if(len == 0) return {0, 0};
    if(len == d[i].slen) return d[i].sval;
    int l = lc(i), r = rc(i);
    if(len <= d[r].slen) {
        return get_suffix(r, len);
    } else {
        return d[r].sval + (get_suffix(l, len - d[r].slen + d[r].plen) - d[r].pval)
            * ipows[d[r].plen] * pows[d[r].slen];
    }
}

node merge(node &L, node &R, int l, int r) {
    node res = {true};
    if(L.slen >= R.plen) {
        if(get_suffix(l, R.plen) != R.pval) {
            res.ok = false;
        }
        else {
            res = node{true, L.plen, L.slen + R.slen - R.plen,
                       L.pval, R.sval + (L.sval - R.pval) * ipows[R.plen] * pows[R.slen]};
        }
    } else {
        if(get_prefix(r, L.slen) != L.sval) {
            res.ok = false;
        }
        else {
            res = {true, L.plen + R.plen - L.slen, R.slen,
                   L.pval + (R.pval - L.sval) * ipows[L.slen] * pows[L.plen], R.sval};
        }
    }
    if(!res.ok) return {false, L.plen, R.slen, L.pval, R.sval};;
    res.ok &= L.ok && R.ok;
    return res;
}


node getnode(int v) {
    if(v > 0) return {true, 0, 1, {0, 0}, {v, v}};
    else return {true, 1, 0, {-v, -v}, {0, 0}};
}

int num[N];

struct Tree {
//    node dat[N * 4];

    void init_dat(int x, int l, int r){
        if(l == r) {
            d[x] = getnode(num[l]);
//            cout << x << ", " << l << ", " << r << ": " << d[x] << endl;

            return ;
        }
        int mid = (l + r) / 2;
        init_dat(lc(x), l, mid);
        init_dat(rc(x), mid + 1, r);
//        if(x == 5) cout << d[lc(x)] << " " << d[rc(x)] << endl;
        d[x] = merge(d[lc(x)], d[rc(x)], lc(x), rc(x));
//        cout << x << ", " << l << ", " << r << ": " << d[x] << endl;

    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            d[x] = getnode(val);
            return ;
        }
        if(pos <= mid) update(pos, lc(x), l, mid, val);
        else update(pos, rc(x), mid+1, r, val);
        d[x] = merge(d[lc(x)], d[rc(x)], lc(x), rc(x));
    }

    node query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {true, 0, 0, {0, 0}, {0, 0}};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return d[x];


        node LHS = query(a, b, lc(x), l, mid);
        node RHS = query(a, b, rc(x), mid+1, r);
//        cout << x << " " << a << " " << b << " " << l << " " << r << " merging " << LHS << " and " << RHS << endl;
        return merge(LHS, RHS, lc(x), rc(x));;
    }
} tree;

int n, k, q, tp, i, t, l, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (sz(pows) < N) pows.push_back(base*pows.back()), ipows.push_back(ibase*ipows.back());
//    for(int i = 0; i < 10; i++) {
//        cout << pows[i] << " " << ipows[i] << endl;
//    }
    cin >> n >> k;
    rep(i, 0, n) cin >> num[i];
    tree.init_dat(0, 0, n - 1);


    cin >> q;
    while(q--) {
        cin >> tp;
        if(tp == 1) {
            cin >> i >> t; i--;
            tree.update(i, 0, 0, n - 1, t);
        }
        else {
            cin >> l >> r; l--, r--;
            node res = tree.query(l, r, 0, 0, n - 1);
//            cout << res.ok << res.pval << " " << res.sval << " " << res.plen << " " << res.slen <<  endl;
            cout << (res.ok && res.plen == 0 && res.slen == 0 ? "Yes" : "No") << '\n';
        }

    }


}