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

mn ways(int N, const auto& g, int ZER, int ONE) {
    vi val(2 * N + 2, -1);

    int cc = 0;
    vi cmp(2 * N + 2, -1);

    val[ZER] = 0;
    val[ONE] = 1;

    for (int i = g.size() - 1; i >= 0; i--) {
        if (cmp[i] != -1) continue;
        if (val[i] == -1) {
            val[i] = 0;
        }

        cmp[i] = cc;
        for (queue<int> bfs({i}); !bfs.empty(); bfs.pop()) {
            int loc = bfs.front();
            for (auto [nbr, bit] : g[loc]) {
                if (val[nbr] != -1 && val[nbr] != val[loc] ^ bit) return 0;
                val[nbr] = val[loc] ^ bit;
                if (cmp[nbr] == -1) {
                    cmp[nbr] = cc;
                    bfs.push(nbr);
                }
            }
        }
        cc++;
    }

    return mn(2).pow(cc - (cmp[ZER] == cmp[ONE] ? 1 : 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;

    int N = s.size();

    mn ans = 0;

    for (int lead = 1; lead < N; lead++) {
        vector<vector<array<int, 2>>> g(2 * N + 2);

        for (int i = 0; i < N; i++) {
            g[i].push_back({ N - 1 - i, 0 });
        }
        for (int i = N + lead; i < 2 * N; i++) {
            g[i].push_back({ 2 * N - 1 - (i - (N + lead)), 0 });
        }
        for (int i = 0; i < N; i++) {
            if (s[i] != '?') {
                g[i].push_back({ i + N, s[i] == '1' });
                g[i + N].push_back({ i, s[i] == '1' });
            }
        }

        const int ZER = 2 * N, ONE = 2 * N + 1;
        for (int i = 0; i < lead; i++) {
            g[ZER].push_back({ N + i, 0 });
            g[N+i].push_back({ ZER, 0 });
        }

        g[0].push_back({ ONE, 0 });
        g[ONE].push_back({ 0, 0 });
        g[N + lead].push_back({ ONE, 0 });
        g[ONE].push_back({ N + lead, 0 });

        ans += ways(N, g, ZER, ONE);
    }

    cout << ans << endl;

    return 0;
}