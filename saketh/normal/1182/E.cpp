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
        while (fact.size() <= n)
            fact.push_back(fact.back() * fact.size());
        return fact[n];
    }
    static modnum ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        return fact(n) / (fact(r) * fact(n - r));
    }
};

template<typename T> struct matrix {
    int N, M;
    T* data;

    matrix<T> (int _N, int _M, T f = 0, T d = 0) : N(_N), M(_M) {
        data = (T*) malloc(N * M * sizeof(T));
        fill(data, data + N * M, f);
        for (int i = 0; i < min(N, M); i++)
            (*this)[i][i] = d;
    }

    matrix<T> (int _N, int _M, const initializer_list<T>& init) : N(_N), M(_M) {
        assert(sz(init) == N * M);
        data = (T*) malloc(N * M * sizeof(T));
        copy(all(init), data);
    }

    matrix<T> (const matrix<T>& m) : N(m.N), M(m.M) {
        data = (T*) malloc(N * M * sizeof(T));
        copy(m.data, m.data + N * M, data);
    }

    ~matrix<T> () { free(data); }

    explicit operator T() const { assert(N == 1 && M == 1); return data[0]; }
    T* operator[](int i) { return data + i * M; }
    const T* operator[](int i) const { return data + i * M; }

    friend matrix<T> operator *(const matrix<T>& a, const matrix<T>& b) {
        assert(a.M == b.N);
        matrix<T> res(a.N, b.M);
        for (int i = 0; i < a.N; i++)
            for (int j = 0; j < b.M; j++)
                for (int k = 0; k < a.M; k++)
                    res[i][j] += a[i][k] * b[k][j];
        return res;
    }

    friend vector<T> operator *(const vector<T>& v, const matrix<T>& m) {
        assert(sz(v) == m.N);
        vector<T> res(m.M);
        for (int j = 0; j < m.M; j++)
            for (int i = 0; i < m.N; i++)
                res[j] += v[i] * m[i][j];
        return res;
    }

    friend vector<T> operator *(const matrix<T>& m, const vector<T>& v) {
        assert(m.M == sz(v));
        vector<T> res(m.N);
        for (int i = 0; i < m.N; i++)
            for (int j = 0; j < m.M; j++)
                res[i] += m[i][j] * v[j];
        return res;
    }

    matrix pow(ll e) const {
        assert(N == M);
        if (e == 0) return matrix<T>(N, M, 0, 1);
        if (e&1) return *this * pow(e - 1);
        return (*this * *this).pow(e / 2);
    }

    int rank() const {
        matrix<T> m = *this;
        int r = 0;
        for (int j = 0; j < M; j++) {
            for (int i = r; i < N; i++) if (m[i][j] != 0) {
                swap_ranges(m[r], m[r] + M, m[i]);
                break;
            }
            if (m[r][j] == 0) continue;

            for (int i = 0; i < N; i++) if (i != r) {
                T c = m[i][j] / m[r][j];
                for (int k = 0; k < M; k++)
                    m[i][k] -= c * m[r][k];
            }
            r++;
        }
        return r;
    }

    friend ostream& operator <<(ostream& os, const matrix<T>& m) {
        for (int i = 0; i < m.N; i++) {
            os << (i ? i < m.N - 1 ? "\u2503" : "\u2517" : "\n\u250F");
            for (int j = 0; j < m.M; j++)
                os << setw(12) << m[i][j];
            os << "  " << (i ? i < m.N - 1 ? "\u2503" : "\u251B" : "\u2512") << "\n";
        }
        return os;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    using mn = modnum<int(1e9 + 7)>;
    using mt = modnum<int(1e9 + 6)>;

    ll N; vector<mn> F(3); mn C;
    cin >> N >> F[0] >> F[1] >> F[2] >> C;

    mt logC = mn::discrete_log(C);

    auto cop = matrix<mt>(3, 3, {
            0, 1, 0,
            0, 0, 1,
            1, 1, 1
    }).pow(N - 3);

    vector<mt> x = {
        mn::discrete_log(F[0]) + logC,
        mn::discrete_log(F[1]) + 2 * logC,
        mn::discrete_log(F[2]) + 3 * logC
    };

    cout << mn::generator().pow(((cop * x).back() - N * logC).v) << endl;

    return 0;
}