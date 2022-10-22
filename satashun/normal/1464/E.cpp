#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <unsigned int MOD>
struct ModInt {
    using uint = unsigned int;
    using ull = unsigned long long;
    using M = ModInt;

    uint v;

    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)
        v = (_v < MOD) ? _v : _v - MOD;
        return *this;
    }

    explicit operator bool() const { return v != 0; }
    M operator+(const M& a) const { return M().set_norm(v + a.v); }
    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
    M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
    M operator/(const M& a) const { return *this * a.inv(); }
    M& operator+=(const M& a) { return *this = *this + a; }
    M& operator-=(const M& a) { return *this = *this - a; }
    M& operator*=(const M& a) { return *this = *this * a; }
    M& operator/=(const M& a) { return *this = *this / a; }
    M operator-() const { return M() - *this; }
    M& operator++(int) { return *this = *this + 1; }
    M& operator--(int) { return *this = *this - 1; }

    M pow(ll n) const {
        if (n < 0) return inv().pow(-n);
        M x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    M inv() const {
        ll a = v, b = MOD, p = 1, q = 0, t;
        while (b != 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(p -= t * q, q);
        }
        return M(p);
    }

    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }
    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    static uint get_mod() { return MOD; }
};

using Mint = ModInt<998244353>;

const Mint zero(0);
const Mint one(1);

bool iszero(Mint x) { return x.v == 0; }

bool isone(Mint x) { return x.v == 1; }

template <class T>
struct Matrix {
    int H, W;
    VV<T> a;
    Matrix() : H(0), W(0) {}
    Matrix(int H, int W) : H(H), W(W), a(VV<T>(H, V<T>(W))) {}
    Matrix(const VV<T>& v) : H(v.size()), W(v[0].size()), a(v) {}
    static Matrix E(int n) {
        Matrix a(n, n);
        rep(i, n) a.set(i, i, 1);
        return a;
    }
    T at(int i, int j) const { return a[i][j]; }
    void set(int i, int j, T v) { a[i][j] = v; }
    Matrix operator+(const Matrix& r) const {
        assert(H == r.H && W == r.W);
        VV<T> v(H, V<T>(W));
        rep(i, H) rep(j, W) v[i][j] = a[i][j] + r.a[i][j];
        return Matrix(v);
    }
    Matrix operator-(const Matrix& r) const {
        assert(H == r.H && W == r.W);
        VV<T> v(H, V<T>(W));
        rep(i, H) rep(j, W) v[i][j] = a[i][j] - r.a[i][j];
        return Matrix(v);
    }
    Matrix operator*(const Matrix& r) const {
        assert(W == r.H);
        VV<T> v(H, V<T>(r.W));
        rep(i, H) rep(k, W) rep(j, r.W) v[i][j] += a[i][k] * r.a[k][j];
        return Matrix(v);
    }
    Matrix& operator+=(const Matrix& r) { return (*this) = (*this) + r; }
    Matrix& operator-=(const Matrix& r) { return (*this) = (*this) - r; }
    Matrix& operator*=(const Matrix& r) { return (*this) = (*this) * r; }

    int sweep(int var) {
        int rank = 0;
        vector<bool> used(H);
        rep(j, var) {
            int i = 0;
            while (i < H && (used[i] || iszero(a[i][j]))) i++;
            if (i == H) continue;
            used[i] = true;
            rank++;
            T t = a[i][j];
            rep(k, W) a[i][k] = a[i][k] / t;
            rep(k, H) if (k != i) {
                T t = a[k][j];
                rep(l, W) a[k][l] = a[k][l] - a[i][l] * t;
            }
        }
        return rank;
    }

    Matrix pow(ll n) const {
        assert(H == W);
        int h = H;
        Matrix x = *this, res(h, h);
        res = E(h);
        while (n > 0) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    friend ostream& operator<<(ostream& o, const Matrix& A) {
        rep(i, A.H) {
            rep(j, A.W) o << A.a[i][j] << " ";
            o << endl;
        }
        return o;
    }
};

/*
Ax = b 
pair(, ) 
(-1,{})
  ?
*/
template <class T>
pair<int, vector<T>> solveLinearEquation(const Matrix<T>& A, vector<T> b) {
    assert(A.H == (int)b.size());
    int H = A.H, W = A.W;
    Matrix<T> X(H, W + 1);
    rep(i, H) rep(j, W) X.set(i, j, A.at(i, j));
    rep(i, H) X.set(i, W, b[i]);
    int rank = X.sweep(W);
    rep(i, H) {
        bool allzero = true;
        rep(j, W) if (!iszero(X.at(i, j))) allzero = false;
        if (allzero) {
            if (!iszero(X.at(i, W))) {  // 0x + 0y + 0z = non0
                return pair<int, vector<T>>(-1, vector<T>());
            }
        }
    }
    vector<bool> done(H);
    vector<T> x(W);
    rep(j, W) {
        int c0 = 0, c1 = 0;
        int I = -1;
        rep(i, H) {
            if (iszero(X.at(i, j)))
                c0++;
            else if (isone(X.at(i, j)))
                c1++, I = i;
        }
        if (c0 == H - 1 && c1 == 1 && !done[I]) {
            x[j] = X.at(I, W);
            done[I] = true;
        }
    }
    return pair<int, vector<T>>(W - rank, x);
}

int main() {
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    VV<int> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].pb(b);
    }

    V<int> gr(n, -1);
    auto dfs = [&](auto&& f, int v) -> int {
        if (gr[v] != -1) return gr[v];
        gr[v] = 0;
        set<int> st;
        for (auto to : g[v]) {
            st.insert(f(f, to));
        }
        while (st.count(gr[v])) gr[v]++;
        return gr[v];
    };

    rep(i, n) dfs(dfs, i);
    debug(gr);

    const int B = 512;
    V<int> cnt(B);
    rep(i, n) cnt[gr[i]]++;
    Matrix<Mint> A = Matrix<Mint>::E(B);
    Mint d = Mint(n + 1).inv();

    rep(i, B) {
        rep(j, B) { A.a[i][j] -= Mint(cnt[i ^ j]) * d; }
    }
    V<Mint> b(B);
    b[0] = d;
    auto res = solveLinearEquation(A, b);
    // debug(res);

    Mint ans = Mint(1) - res.se[0];
    cout << ans << endl;

    return 0;
}