#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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
const int MOD = 1e9 + 7;
using mint = modnum<MOD>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi val(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }

    vvi ch(N);
    for (int i = 1; i < N; i++) {
        int par;
        cin >> par;
        ch[par - 1].push_back(i);
    }

    vll sum(N);
    for (int i = N - 1; i >= 0; i--) {
        sum[i] = val[i];
        for (int j : ch[i])
            sum[i] += sum[j];
    }

    vi ctm(N + 1);
    for (int i = 0; i < N; i++) {
        ll k = sum[0] / gcd(sum[0], sum[i]);
        for (ll mk = k; mk <= N; mk += k)
            ctm[mk]++;
    }

    vector<mint> dp(N + 1);
    for (int k = N; k > 0; k--) {
        if (ctm[k] == k) {
            dp[k] = 1;
            for (int m = 2 * k; m <= N; m += k)
                dp[k] += dp[m];
        }
    }

    cout << dp[1] << endl;

    return 0;
}