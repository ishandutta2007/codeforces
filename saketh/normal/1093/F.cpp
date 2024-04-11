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
using mn = modnum<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const int MAXK = 100;

    int N, K, L;
    cin >> N >> K >> L;

    vi vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        if (vals[i] > 0) vals[i]--;
    }

    vector<array<mn, MAXK>> eq(N);
    vector<array<mn, MAXK>> ne(N);
    vector<array<mn, MAXK>> pref(N + 1);
    vi app(K, -1);

    for (int v = 0; v < K; v++) {
        pref[0][v] = 1;
    }

    for (int i = 0; i < N; i++) {
        if (vals[i] != -1) {
            for (int v = 0; v < K; v++) {
                if (v != vals[i])
                    app[v] = i;
            }
        }

        for (int v = 0; v < K; v++) {
            if (app[v] == i) continue;
            int sm = min(L - 1, i - app[v]);
            eq[i][v] += pref[i][v] - (i - sm >= 0 ? pref[i - sm][v] : 0);
        }

        mn sum = 0;
        for (int v = 0; v < K; v++) {
            sum += eq[i][v];
        }
        for (int v = 0; v < K; v++) {
            ne[i][v] = sum - eq[i][v];
            pref[i+1][v] = pref[i][v] + ne[i][v];
        }
    }

    cout << eq[N-1][0] + ne[N-1][0] << endl;

    return 0;
}