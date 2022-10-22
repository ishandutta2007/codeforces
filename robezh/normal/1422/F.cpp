#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)2e5 + 50, S = 450;

int ncnt = 1;
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

struct node{
    int ls, rs;
    mi sum;
} ns[N * 30];

int newnode(mi val){
    ns[ncnt].ls = ns[ncnt].rs = 0;
    ns[ncnt].sum = val;
    return ncnt++;
}

int newnode(int ls, int rs){
    ns[ncnt].ls = ls;
    ns[ncnt].rs = rs;
    ns[ncnt].sum = (ls ? ns[ls].sum : 1) * (rs ? ns[rs].sum : 1);
    return ncnt++;
}

int n;
int vs[N];
int las[N];

int build(int tl, int tr){
    if(tl == tr) return newnode(mi(1));
    int mid = (tl + tr) / 2;
    return newnode(build(tl, mid), build(mid + 1, tr));
}

mi get_sum(int v, int l, int r, int tl, int tr){
    if(tr < l || tl > r) return mi(1);
    if(l <= tl && tr <= r) return ns[v].sum;
    int tm = (tl + tr) / 2;

    return get_sum(ns[v].ls, l, r, tl, tm) * get_sum(ns[v].rs, l, r, tm + 1, tr);
}

int update(int v, int pos, int tl, int tr, mi val){
    if(tl == tr) return newnode(ns[v].sum * val);
    int tm = (tl + tr) / 2;
    if(pos <= tm) return newnode(update(ns[v].ls, pos, tl, tm, val), ns[v].rs);
    else return newnode(ns[v].ls, update(ns[v].rs, pos, tm+1, tr, val));
}

int curnd[S];
int a[N];
int p[N], pos[N];
vi pm;
pii nd[N][100];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(p, p + N, 1);
    rep(i, 2, N) {
        if(p[i]) {
            if(i < S) {
                pos[i] = sz(pm);
                pm.push_back(i);
            }
            for(int j = 2 * i; j < N; j += i) p[j] = 0;
        }
    }

    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    vs[0] = build(1, n);
    memset(curnd, -1, sizeof(curnd));
    rep(i, 1, n + 1) {
        for(int x : pm) {
            int ps = pos[x];
            int cnt = 0;
            while(a[i] % x == 0) a[i] /= x, cnt++;
            nd[i][ps].second = cnt;
            while(curnd[ps] != -1 && nd[curnd[ps]][ps].second <= cnt) curnd[ps] = nd[curnd[ps]][ps].first;
            nd[i][ps].first = curnd[ps];
//            cout << i << " " << x << " to " << curnd[ps] << " with val " << nd[i][ps].second << '\n';
            curnd[ps] = i;
        }
        vs[i] = vs[i - 1];
        if(a[i] > 1) {
            assert(a[i] >= S);
            if(las[a[i]]) vs[i] = update(vs[i], las[a[i]], 1, n, inv(mi(a[i])));
            vs[i] = update(vs[i], i, 1, n, a[i]);
            las[a[i]] = i;
        }
    }

    int q;
    cin >> q;
    int ans = 0;
    while(q--) {
        int l, r; cin >> l >> r;
        l = (ans + l) % n + 1, r = (ans + r) % n + 1;
        if(l > r) swap(l, r);
//        cout << "asking " << l << " " << r << endl;
        mi res = 1;
        for(int j = 0; j < sz(pm); j++) {
            int cur = r;
            while(true) {
                int nxt = nd[cur][j].first;
                if(nxt >= l) cur = nxt;
                else break;
            }
            res *= pow(mi(pm[j]), nd[cur][j].second);
        }
        res *= get_sum(vs[r], l, r, 1, n);

        ans = int(res);
        cout << ans << '\n';
    }
 }