#line 1 "test.cpp"
//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
template<class T> using pq = priority_queue<T,vector<T>,greater<T>>;
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(a,b,c,name,...) name
#define rep1(n) for (ll UNUSED_NUMBER = 0; UNUSED_NUMBER < (n); ++UNUSED_NUMBER)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep2(i,n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep3(i,a,b) for(ll i = (b) - 1;i >= (a);i--)
#define rrep4(i,a,b,c) for(ll i = (a) + ((b)-(a)-1) / (c) * (c);i >= (a);i -= c)
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class... Ts> void in(Ts&... t);
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); in(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); in(name)
ll intpow(ll a, ll b){ ll ans = 1; while(b){if(b & 1) ans *= a; a *= a; b /= 2;} return ans;}
ll modpow(ll a, ll b, ll p){ ll ans = 1; a %= p;while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
ll GCD(ll a,ll b) { if(a == 0 || b == 0) return a + b; if(a % b == 0) return b; else return GCD(b,a%b);}
ll LCM(ll a,ll b) { if(a == 0) return b; if(b == 0) return a;return a / GCD(a,b) * b;}
namespace IO{
#define VOID(a) decltype(void(a))
struct setting{ setting(){cin.tie(nullptr); ios::sync_with_stdio(false);fixed(cout); cout.precision(12);}} setting;
template<int I> struct P : P<I-1>{};
template<> struct P<0>{};
template<class T> void i(T& t){ i(t, P<3>{}); }
void i(vector<bool>::reference t, P<3>){ int a; i(a); t = a; }
template<class T> auto i(T& t, P<2>) -> VOID(cin >> t){ cin >> t; }
template<class T> auto i(T& t, P<1>) -> VOID(begin(t)){ for(auto&& x : t) i(x); }
template<class T, size_t... idx> void ituple(T& t, index_sequence<idx...>){
    in(get<idx>(t)...);}
template<class T> auto i(T& t, P<0>) -> VOID(tuple_size<T>{}){
    ituple(t, make_index_sequence<tuple_size<T>::value>{});}
#undef VOID
}
#define unpack(a) (void)initializer_list<int>{(a, 0)...}
template<class... Ts> void in(Ts&... t){ unpack(IO :: i(t)); }
#undef unpack
//constexpr int mod = 1000000007;
constexpr int mod = 998244353;
static const double PI = 3.1415926535897932;
template <class F> struct REC {
    F f;
    REC(F &&f_) : f(forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, forward<Args>(args)...); }};

#line 2 "library/modint/Modint.hpp"
template <int mod>
struct Modint{
    int x;
    Modint():x(0) {}
    Modint(long long y): x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    Modint &operator += (const Modint &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;}
    Modint &operator -= (const Modint &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;}
    Modint &operator *= (const Modint &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;}
    Modint &operator /= (const Modint &p) {
        *this *= p.inverse();
        return *this;}
    Modint operator -() const{return Modint(-x);}
    Modint operator +(const Modint &p) const {return Modint(*this) += p;}
    Modint operator -(const Modint &p) const {return Modint(*this) -= p;}
    Modint operator *(const Modint &p) const {return Modint(*this) *= p;}
    Modint operator /(const Modint &p) const {return Modint(*this) /= p;}
    Modint &operator ++() {if(x == mod - 1) x = 0; else x++; return *this;}
    Modint &operator --() {if(x == 0) x = mod - 1; else x--; return *this;} 
    bool operator == (const Modint &p) const {return x == p.x;}
    bool operator != (const Modint &p) const {return x != p.x;}
    Modint inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return Modint(u);}
    Modint pow(long long n) const {
        Modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;}
    friend ostream &operator<<(ostream &os, const Modint &p) { return os << p.x; }
    friend istream &operator>>(istream &is, Modint &a) {
        long long t;
        is >> t;
        a = Modint<mod>(t);
        return (is);
    }
    static constexpr int get_mod() {return mod;}
};
#line 87 "test.cpp"
using mint = Modint<mod>;
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

template<typename T,int H,int W>
struct Matrix {
    using Array = array<array<T,W>,H>;
    Array A;
    Matrix():A() {
        for(int i = 0;i < H;i++) {
            for(int j = 0;j < W;j++) {
                (*this)[i][j] = T();
            }
        }
    }
    int height() const {return H;}
    int width() const {return W;}
    inline const array<T,W> &operator[](int k) const {return A[k];}
    inline array<T,W> &operator[](int k){return A[k];}
    static Matrix I() {
        assert(H == W);
        Matrix mat;
        for(int i = 0;i < H;i++) mat[i][i] = 1;
        return (mat);
    }
    Matrix &operator+=(const Matrix &B) {
        for(int i = 0;i < H;i++) {
            for(int j = 0;j < W;j++) {
                A[i][j] += B[i][j];
            }
        }
        return (*this);
    }
    Matrix &operator-=(const Matrix &B) {
        for(int i = 0;i < H;i++) {
            for(int j = 0;j < W;j++) {
                A[i][j] -= B[i][j];
            }
        }
        return (*this);
    }
    Matrix &operator*=(const Matrix &B) {
        assert(H == W);
        Matrix C;
        for(int i = 0;i < H;i++) {
            for(int k = 0;k < H;k++) {
                for(int j = 0;j < H;j++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        A.swap(C.A);
        return (*this);
    }
    Matrix &operator^=(long long k) {
        Matrix B = Matrix::I();
        while(k > 0) {
            if(k & 1) B *= this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(B.A);
        return (*this);
    }
    Matrix operator+(const Matrix &B) const{return (Matrix(*this) += B);}
    Matrix operator-(const Matrix &B) const{return (Matrix(*this) -= B);}
    Matrix operator*(const Matrix &B) const{return (Matrix(*this) *= B);}
    Matrix operator^(const Matrix &B) const{return (Matrix(*this) ^= B);}
    bool operator==(const Matrix &B) const {
        for(int i = 0;i < H;i++) {
            for(int j = 0;j < W;j++) {
                if(A[i][j] != B[i][j]) return false;
            }
        }
        return true;
    }
    bool operator!=(const Matrix &B) const {
        for(int i = 0;i < H;i++) {
            for(int j = 0;j < W;j++) {
                if(A[i][j] != B[i][j]) return true;
            }
        }
        return false;
    }
    friend ostream &operator<<(ostream &os,const Matrix &p) {
        for(int i = 0;i < H;i++) {
            os << "[";
            for(int j = 0;j < W;j++) {
                os << p[i][j] << (j+1 == W ?"]\n":",");
            }
        }
        return(os);
    }
    T determinant(int n = -1) {
        if(n == -1) n = H;
        Matrix B(*this);
        T ret = 1;
        for(int i = 0;i < n;i++) {
            int idx = -1;
            for(int j = i;j < n;j++) {
                if(B[j][i] != 0) {
                    idx = j;
                    break;
                }
            }
            if(idx == -1) return 0;
            if(i != idx) {
                ret *= T(-1);
                swap(B[i],B[idx]);
            }
            ret *= B[i][i];
            T inv = T(1) / B[i][i];
            for(int j = 0;j < n;j++) {
                B[i][j] *= inv;
            }
            for(int j = i+1;j < n;j++) {
                T a = B[j][i];
                if(a == 0) continue;
                for(int k = i;k < n;k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return(ret);
    }
};
#line 2 "library/segtree/lazysegtree.hpp"
using namespace std;
template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n, e())) {}
    explicit lazy_segtree(const vector<S>& v) : _n(int(v.size())) {
        log = 0;
        while ((1U << log) < (unsigned int)(_n)) log++;
        size = 1 << log;
        d = vector<S>(2 * size, e());
        lz = vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    vector<S> d;
    vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};
#line 215 "test.cpp"
using mat = Matrix<mint,2,2>;
pair<mint,mint> op(pair<mint,mint> x,pair<mint,mint> y) {return make_pair(x.first + y.first,x.second + y.second);}
pair<mint,mint> e() {return make_pair(mint(0),mint(0));}
pair<mint,mint> mapping(mat f,pair<mint,mint> x) {return make_pair(x.first * f[0][0] + x.second * f[0][1],x.first * f[1][0] + x.second * f[1][1]);}
mat II = mat::I();
mat composition(mat l,mat r) {
    return l * r;
}
mat id() {return II;}
int main() {
INT(n);
    vpii lr(n);
    rep(i,n) cin >> lr[i].first >> lr[i].second;
    int ma = 0;
    rep(i,n) chmax(ma,lr[i].second);
    mat m1,m2;
    m1[0][0] = 2;
    m1[0][1] = 2;
    m1[1][0] = 1;
    m1[1][1] = 1;
    m2[0][0] = 2;
    m2[1][0] = 1;
    m2[1][1] = 3;
    vector<pair<mint,mint>> v(ma+2,e());
    rep(i,ma+2) {
        if(lr[0].first <= i && i <= lr[0].second) v[i].first = 1;
        else v[i].second = 1;
    }
    lazy_segtree<pair<mint,mint>,op,e,mat,mapping,composition,id> seg(v);
    rep(i,1,n) {
        seg.apply(0,lr[i].first,m2);
        seg.apply(lr[i].first,lr[i].second+1,m1);
        seg.apply(lr[i].second+1,ma+2,m2);
    }
    cout << seg.all_prod().first << '\n';
}