#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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
using vmn = vector<mn>;

mn way[50][50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll N;
    int K;
    cin >> N >> K;

    vmn inv(51);
    for (int v = 1; v <= 50; v++)
        inv[v] = mn(1) / v;

    for (int d = 0; d < 50; d++) {
        way[d][d] = 1;
    }
    for (int k = 0; k < K; k++) {
        for (int s = 49; s >= 0; s--) {
            mn pref = 0;
            for (int e = s; e >= 0; e--) {
                way[s][e] *= inv[e + 1];
                pref += way[s][e];
                way[s][e] = pref;
            }
        }
    }

    vector<pair<ll, int>> mult;
    for (ll v = 2; v * v <= N; v++) {
        if (N % v != 0) continue;
        int p = 0;
        for (; N % v == 0; N /= v)
            p++;
        mult.emplace_back(v, p);
    }
    if (N > 1) mult.emplace_back(N, 1);

    mn ans = 1;
    for (auto [pr, ct] : mult) {
        mn ctr = 0, pwr = 1;
        for (int cp = 0; cp <= ct; cp++) {
            ctr += pwr * way[ct][cp];
            pwr *= pr;
        }
        ans *= ctr;
    }
    cout << ans << endl;

    return 0;
}