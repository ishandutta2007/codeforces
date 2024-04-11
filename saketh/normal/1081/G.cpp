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

int MOD;
struct modnum {
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
using mn = modnum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K >> MOD;

    if (K >= 20 || (1 << (K - 1)) >= N) {
        cout << 0 << endl;
        return 0;
    }

    int ct = 1 << (K - 1);
    int ctB = N % ct;
    int ctA = ct - ctB;
    int szA = N / ct;
    int szB = szA + 1;

    vector<mn> recip(N + 1), pref(N + 1);
    for (int i = 1; i <= N; i++) {
        recip[i] = mn(1) / i;
        pref[i] = pref[i-1] + recip[i];
    }

    auto comb = [&](int a, int b) {
        mn res = 0;
        for (int i = 1; i <= a; i++) {
            // sum of 1/2 - 1/(i+j) for j in [1, b]
            res += mn(b)/2 - (pref[i + b] - pref[i]);
        }
        return res;
    };

    mn ans = 0;
    ans += mn(ctA) * szA * (szA - 1) / 4;
    if (ctA > 1) ans += mn(ctA) * (ctA - 1) / 2 * comb(szA, szA);
    ans += mn(ctB) * szB * (szB - 1) / 4;
    if (ctB > 1) ans += mn(ctB) * (ctB - 1) / 2 * comb(szB, szB);
    if (ctA > 0 && ctB > 0) ans += mn(ctA) * ctB * comb(szA, szB);
    cout << ans << endl;

    return 0;
}