#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<int MOD> struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend istream& operator >> (istream& i, modnum& n) { ll v; i >> v; n = modnum(v); return i; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(ll e) const {
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

    static int totient() {
        int tot = MOD, tmp = MOD;
        for (int p = 2; p * p <= tmp; p++) if (tmp % p == 0) {
            tot = tot / p * (p - 1);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot = tot / tmp * (tmp - 1);
        return tot;
    }

    static int primitive_root() {
        if (MOD == 1) return 0;
        if (MOD == 2) return 1;

        int tot = totient(), tmp = tot;
        vi tot_pr;
        for (int p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);

        for (int r = 2; r < MOD; r++) if (__gcd(r, MOD) == 1) {
            bool root = true;
            for (int p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }

    static modnum generator() { static modnum g = primitive_root(); return g; }
    static int discrete_log(modnum v) {
        static const int M = ceil(sqrt(MOD));
        static unordered_map<int, int> table;
        if (table.empty()) {
            modnum e = 1;
            for (int i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }
        }
        static modnum f = generator().pow(totient() - M);

        for (int i = 0; i < M; i++) {
            if (table.count(v.v)) return table[v.v] + i * M;
            v *= f;
        }
        assert(false);
    }

    static modnum fact(int n) {
        static vector<modnum<MOD>> fact = { 1 };
        for (assert(n >= 0); fact.size() <= n; )
            fact.push_back(fact.back() * fact.size());
        return fact[n];
    }

    static modnum finv(int n) {
        static vector<modnum<MOD>> finv = { 1 };
        for (assert(n >= 0); finv.size() <= n; )
            finv.push_back(finv.back() / finv.size());
        return finv[n];
    }

    static modnum ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        return fact(n) * finv(r) * finv(n - r);
    }
};
using mn = modnum<int(1e9 + 7)>;
using vmn = vector<mn>;

int inx[51][51][51];
mn ways[6000][2501];
mn order[51][51][51][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T;
    cin >> N >> T;

    vi t(N), g(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i] >> g[i];
        --g[i];
    }

    memset(inx, 0xff, sizeof(inx));

    vector<array<int, 3>> active = {{ 0, 0, 0 }};
    inx[0][0][0] = 0;
    ways[0][0] = 1;

    for (int i = 0; i < N; i++) {
        vector<array<int, 3>> intro;

        for (auto ct : active) {
            int cur_inx = inx[ct[0]][ct[1]][ct[2]];

            auto sc = ct; sc[g[i]]++;
            int& succ_inx = inx[sc[0]][sc[1]][sc[2]];
            if (succ_inx == -1) {
                succ_inx = sz(active) + sz(intro);
                intro.push_back(sc);
            }

            for (int tt = 0; tt < T; tt++) if (ways[cur_inx][tt].v) {
                ways[succ_inx][tt + t[i]] += ways[cur_inx][tt];
            }
        }

        for (auto p : intro) active.push_back(p);
        sort(all(active));
        reverse(all(active));
    }

    order[1][0][0][0] = 1;
    order[0][1][0][1] = 1;
    order[0][0][1][2] = 1;

    for (int a = 0; a < N; a++) {
        for (int b = 0; a + b < N; b++) {
            for (int c = 0; a + b + c < N; c++) {
                order[a+1][b][c][0] += order[a][b][c][1];
                order[a+1][b][c][0] += order[a][b][c][2];

                order[a][b+1][c][1] += order[a][b][c][0];
                order[a][b+1][c][1] += order[a][b][c][2];

                order[a][b][c+1][2] += order[a][b][c][0];
                order[a][b][c+1][2] += order[a][b][c][1];
            }
        }
    }

    mn ans = 0;
    for (auto ct : active) {
        int cur_inx = inx[ct[0]][ct[1]][ct[2]];

        mn ord = 0;
        for (int i = 0; i < 3; i++)
            ord += order[ct[0]][ct[1]][ct[2]][i];
        ord *= mn::fact(ct[0]) * mn::fact(ct[1]) * mn::fact(ct[2]);

        ans += ways[cur_inx][T] * ord;
    }
    cout << ans << endl;

    return 0;
}