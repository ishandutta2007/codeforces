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

    modnum inv() const {
        int g = MOD, x = 0, y = 1;
        for (int r = v; r != 0; ) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }
};
using mn = modnum<998244353>;
using vmn = vector<mn>;
using vvmn = vector<vmn>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C;
    cin >> N >> C;
    const int K = N / C;

    vi val(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
        --val[i];
    }

    vmn pow2(N + 1);
    pow2[0] = 1;
    for (int e = 1; e <= N; e++) {
        pow2[e] = 2 * pow2[e-1];
    }

    vmn atl(N + 2);
    atl[0] = pow2[N] - 1;

    if (C > log(N) / log(2)) {
        vvmn dp(N + 1, vmn(K + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < N; i++) {
            vi ct(C);
            ct[val[i]] = 1;
            int seen = 1;
            mn ways = seen == C;

            for (int j = i; j >= 0; j--) {
                if (val[j] != val[i]) {
                    ct[val[j]]++;
                    if (ct[val[j]] == 1) {
                        seen++;
                        if (seen == C) {
                            ways = 1;
                            for (int v = 0; v < C; v++)
                                ways *= pow2[ct[v]] - 1;
                        }
                    } else if (seen == C) {
                        ways /= pow2[ct[val[j]] - 1] - 1;
                        ways *= pow2[ct[val[j]]] - 1;
                    }
                }
                for (int k = 1; k <= K; k++) {
                    if (dp[j][k-1].v)
                        dp[i+1][k] += ways * dp[j][k-1];
                }
            }
            for (int k = 0; k <= K; k++) {
                atl[k] += dp[i+1][k] * pow2[N - i - 1];
            }
        }
    } else {
        const int MM = 1 << C;
        vvmn dp(K + 2, vmn(MM, 0));
        dp[0][0] = 1;

        for (int i = 0; i < N; i++) {
            for (int k = K; k >= 0; k--) {
                for (int m = MM - 2; m >= 0; m--) {
                    if (!dp[k][m].v) continue;
                    if (m & (1 << val[i])) {
                        dp[k][m] *= 2;
                    } else {
                        int mm = m ^ (1 << val[i]);
                        if (mm == MM - 1) {
                            dp[k+1][0] += dp[k][m];
                            atl[k+1] += dp[k][m] * pow2[N - i - 1];
                        } else {
                            dp[k][mm] += dp[k][m];
                        }
                    }
                }
            }
        }
    }

    for (int k = 0; k <= N; k++) {
        if (k) cout << " ";
        cout << atl[k] - atl[k+1];
    }
    cout << endl;

    return 0;
}