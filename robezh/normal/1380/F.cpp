#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define lson(x) 2*x+1
#define rson(x) 2*x+2


const int MOD = 998244353;

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

const int N = (int)5e5 + 50;

struct node {
    int d0, d1;
    mi s00, s01, s10, s11;

    void merge(node &L, node &R) {
        d0 = L.d0;
        d1 = R.d1;
        s00 = L.s00 * R.s00 + (L.d1 == 1 ? L.s01 * R.s10 * (9 - R.d0) : 0);
        s01 = L.s00 * R.s01 + (L.d1 == 1 ? L.s01 * R.s11 * (9 - R.d0) : 0);
        s10 = L.s10 * R.s00 + (L.d1 == 1 ? L.s11 * R.s10 * (9 - R.d0) : 0);
        s11 = L.s10 * R.s01 + (L.d1 == 1 ? L.s11 * R.s11 * (9 - R.d0) : 0);
    }
};

node newnode(int d) {
    return node{d, d, d + 1, 1, 1, 0};
}

int d[N];

struct Tree {
    node dat[N * 4];

    void init_dat(int x, int l, int r){
        if(l == r){
            dat[x] = newnode(d[l]);
            return ;
        }
        int mid = (l + r) / 2;
        init_dat(lson(x), l, mid);
        init_dat(rson(x), mid+1, r);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r, int dx){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = newnode(dx);
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, dx);
        else update(pos, rson(x), mid+1, r, dx);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }
} tree;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    string str;
    cin >> str;
    rep(i, 0, n) d[i] = str[i] - '0';
    tree.init_dat(0, 0, n - 1);
    rep(i, 0, m) {
        int pos, dx; cin >> pos >> dx; pos--;
        tree.update(pos, 0, 0, n - 1, dx);
        cout << int(tree.dat[0].s00) << '\n';
    }
}