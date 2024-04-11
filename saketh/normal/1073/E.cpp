#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

template<int MOD> struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }
    friend istream& operator << (istream& i, modnum& n) { ll v; i >> v; n = modnum(v); return i; }

    friend bool operator == (const modnum& a, const modnum &b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum &b) { return a.v != b.v; }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(int e) {
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }
};
using num = modnum<998244353>;

int mask(ll v) {
    int res = 0;
    for (; v; v /= 10)
        res |= 1 << (v % 10);
    return res;
}

typedef array<array<num, 2>, 1024> arr;
arr go(ll A, ll B) {
    arr res;
    if (A/10 < B/10) {
        arr sub = go(A/10, B/10);
        for (int m = 0; m < 1024; m++) {
            for (int e = 0; e < 10; e++) {
                int nm = m | (1 << e);
                res[nm][0] += sub[m][0];
                res[nm][1] += sub[m][1] * 10 + sub[m][0] * e;
            }
        }
        for (ll v = A+1; v < A/10*10+10; v++) {
            res[mask(v)][0] += 1;
            res[mask(v)][1] += v;
        }
        for (ll v = B/10*10; v < B; v++) {
            res[mask(v)][0] += 1;
            res[mask(v)][1] += v;
        }
    } else {
        for (ll v = A+1; v < B; v++) {
            res[mask(v)][0] += 1;
            res[mask(v)][1] += v;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll L, R; int K;
    cin >> L >> R >> K;
    arr res = go(L - 1, R + 1);
    num ans = 0;
    for (int m = 0; m < 1024; m++) {
        if (__builtin_popcount(m) <= K)
            ans += res[m][1];
    }
    cout << ans << endl;
    return 0;
}