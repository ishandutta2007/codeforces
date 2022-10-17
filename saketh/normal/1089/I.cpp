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
using vb = vector<bool>;
using vs = vector<string>;

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

    modnum pow(int e) {
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }
};
using mn = modnum;
using vmn = vector<mn>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T >> MOD;

    const int MAXV = 401;

    vmn fact(MAXV);
    fact[0] = 1;
    for (int i = 1; i < MAXV; i++)
        fact[i] = fact[i-1] * i;

    vmn nopref(MAXV);
    nopref[1] = 1;
    for (int i = 2; i < MAXV; i++) {
        nopref[i] = fact[i];
        for (int j = 1; j < i; j++)
            nopref[i] -= nopref[j] * fact[i-j];
    }

    vector<vmn> sect(MAXV, vmn(MAXV, 0));
    sect[0][0] = 1;
    sect[1][1] = 1;
    for (int i = 2; i < MAXV; i++) {
        for (int s = 1; s <= i; s++) {
            for (int l = 1; l <= i; l++)
                sect[i][s] += sect[i-l][s-1] * fact[l];
        }
    }

    vmn good(MAXV);
    good[1] = 1;
    for (int i = 2; i < MAXV; i++) {
        good[i] = fact[i];
        for (int ps = 1; ps < i; ps++) {
            if (ps > 1 || i - ps > 1)
                good[i] -= 2 * nopref[ps] * fact[i - ps];
        }
        for (int ss = 3; ss < i; ss++) {
            good[i] -= sect[i][ss] * good[ss];
        }
    }

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        cout << good[n] << "\n";
    }

    return 0;
}