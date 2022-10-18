#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<int MOD> struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }
    friend istream& operator << (istream& i, modnum& n) { ll v; i >> v; n = modnum(v); return i; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(int e) const {
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    /* requires prime MOD */
    modnum& operator /= (const modnum& o) { return (*this) *= o.pow(MOD - 2); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }
};
const int MOD = 1e9 + 7;
using mn = modnum<MOD>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const int MAXN = 1e6 + 1;

    vector<mn> fact(MAXN), finv(MAXN);
    fact[0] = finv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * i;
        finv[i] = finv[i-1] / i;
    }

    auto ncr = [&](int n, int r) {
        if (r > n) return mn(0);
        return fact[n] * finv[r] * finv[n-r];
    };

    int N, M, A, B;
    cin >> N >> M >> A >> B;

    vector<mn> npow(MAXN), mpow(MAXN);
    npow[0] = mpow[0] = 1;
    for (int e = 1; e < MAXN; e++) {
        npow[e] = N * npow[e-1];
        mpow[e] = M * mpow[e-1];
    }

    mn ans = 0;
    for (int bw = 0; bw <= N - 2; bw++) {
        mn ways = fact[N - 2] * finv[N - 2 - bw];
        int cc = bw + 2;
        if (cc < N) ways *= cc * npow[N - cc - 1];
        ways *= ncr(M - bw - 1 + bw, bw);
        ways *= mpow[N - 1 - bw - 1];
        ans += ways;
    }

    cout << ans << endl;
    return 0;
}