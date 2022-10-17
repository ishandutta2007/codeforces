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

    /* requires prime modulus */
    modnum inv() const { return this->pow(MOD - 2); }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }
};

template<typename T> struct matrix {
    int N;
    vector<T> dat;

    matrix<T> (int _N, T fill = T(0), T diag = T(1)) : N(_N) {
        dat.resize(N * N, fill);
        for (int i = 0; i < N; i++)
            (*this)(i, i) = diag;
    }

    T& operator()(int i, int j) {
        return dat[N * i + j];
    }

    matrix<T> operator *(const matrix<T>& b) const {
        matrix<T> r(N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    r(i, j) += (*this)(i, k) * b(k, j);
        return r;
    }

    matrix<T> pow(ll e) {
        if(!e) return matrix<T>(N);
        if (e&1) return *this * *this.pow(e - 1);
        return (*this * *this).pow(e/2);
    }

    int rank() const {
        matrix<T> m = *this;
        int r = 0;
        for (int i = 0; i < N; i++) {
            for (int j = r; j < N; j++) {
                if (m(j, i) != T(0)) {
                    for (int k = 0; k < N; k++)
                        swap(m(r, k), m(j, k));
                    break;
                }
            }
            if (m(r, i) == T(0)) continue;
            for (int j = 0; j < N; j++) {
                if (j == r) continue;
                T coeff = m(j, i) / m(r, i);
                for (int k = 0; k < N; k++)
                    m(j, k) -= coeff * m(r, k);
            }
            r++;
        }
        return r;
    }

    friend ostream& operator<<(ostream& os, const matrix<T>& m) {
        os << "{";
        for (int i = 0; i < m.N; i++) {
            if(i) os << "},\n ";
            os << "{";
            for (int j = 0; j < m.N; j++) {
                if(j) os << ", ";
                os << setw(10) << m(i, j) << setw(0);
            }
        }
        return os << "}}";
    }
};

int maximum_matching(const int N, const vector<array<int, 2>>& edges) {
    const int INF = 1e9 + 7;
    using mn = modnum<INF>;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> unif(1, INF - 1);

    int res = 0;
    for (int rep = 0; rep < 10; rep++) {
        matrix<mn> m(N, 0, 0);
        for (auto [u, v] : edges) {
            if (u > v) swap(u, v);
            int eid = unif(rng);
            m(u, v) = eid;
            m(v, u) = -eid;
        }
        res = max(res, m.rank());
    }
    return res;
}

void solve() {
    int C, L;
    cin >> C >> L;
    int N = 2 * C + L;

    vector<array<int, 2>> edges;
    for (int c = 0; c < C; c++) {
        edges.push_back({ c, c + C });
        string s;
        cin >> s;
        for (int l = 0; l < L; l++) {
            if (s[l] == '1') {
                edges.push_back({ c, 2 * C + l });
                edges.push_back({ c + C, 2 * C + l });
            }
        }
    }

    cout << maximum_matching(N, edges)/2 - C << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;

}