#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int MAX=300005;
const ll INF=1LL<<60;

//modint

// from: https://gist.github.com/yosupo06/ddd51afb727600fd95d9d8ad6c3c80c9
// (based on AtCoder STL)

#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {
    
    namespace internal {
        
#ifndef _MSC_VER
        template <class T>
        using is_signed_int128 =
        typename std::conditional<std::is_same<T, __int128_t>::value ||
        std::is_same<T, __int128>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_unsigned_int128 =
        typename std::conditional<std::is_same<T, __uint128_t>::value ||
        std::is_same<T, unsigned __int128>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using make_unsigned_int128 =
        typename std::conditional<std::is_same<T, __int128_t>::value,
        __uint128_t,
        unsigned __int128>;
        
        template <class T>
        using is_integral = typename std::conditional<std::is_integral<T>::value ||
        is_signed_int128<T>::value ||
        is_unsigned_int128<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                         std::is_signed<T>::value) ||
        is_signed_int128<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_unsigned_int =
        typename std::conditional<(is_integral<T>::value &&
                                   std::is_unsigned<T>::value) ||
        is_unsigned_int128<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using to_unsigned = typename std::conditional<
        is_signed_int128<T>::value,
        make_unsigned_int128<T>,
        typename std::conditional<std::is_signed<T>::value,
        std::make_unsigned<T>,
        std::common_type<T>>::type>::type;
        
#else
        
        template <class T> using is_integral = typename std::is_integral<T>;
        
        template <class T>
        using is_signed_int =
        typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_unsigned_int =
        typename std::conditional<is_integral<T>::value &&
        std::is_unsigned<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using to_unsigned = typename std::conditional<is_signed_int<T>::value,
        std::make_unsigned<T>,
        std::common_type<T>>::type;
        
#endif
        
        template <class T>
        using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
        
        template <class T>
        using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
        
        template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
        
    }  // namespace internal
    
}  // namespace atcoder

#include <utility>

namespace atcoder {
    
    namespace internal {
        
        constexpr long long safe_mod(long long x, long long m) {
            x %= m;
            if (x < 0) x += m;
            return x;
        }
        
        struct barrett {
            unsigned int _m;
            unsigned long long im;
            
            barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
            
            unsigned int umod() const { return _m; }
            
            unsigned int mul(unsigned int a, unsigned int b) const {
                
                unsigned long long z = a;
                z *= b;
#ifdef _MSC_VER
                unsigned long long x;
                _umul128(z, im, &x);
#else
                unsigned long long x =
                (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
                unsigned int v = (unsigned int)(z - x * _m);
                if (_m <= v) v += _m;
                return v;
            }
        };
        
        constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
            if (m == 1) return 0;
            unsigned int _m = (unsigned int)(m);
            unsigned long long r = 1;
            unsigned long long y = safe_mod(x, m);
            while (n) {
                if (n & 1) r = (r * y) % _m;
                y = (y * y) % _m;
                n >>= 1;
            }
            return r;
        }
        
        constexpr bool is_prime_constexpr(int n) {
            if (n <= 1) return false;
            if (n == 2 || n == 7 || n == 61) return true;
            if (n % 2 == 0) return false;
            long long d = n - 1;
            while (d % 2 == 0) d /= 2;
            for (long long a : {2, 7, 61}) {
                long long t = d;
                long long y = pow_mod_constexpr(a, t, n);
                while (t != n - 1 && y != 1 && y != n - 1) {
                    y = y * y % n;
                    t <<= 1;
                }
                if (y != n - 1 && t % 2 == 0) {
                    return false;
                }
            }
            return true;
        }
        template <int n> constexpr bool is_prime = is_prime_constexpr(n);
        
        constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
            a = safe_mod(a, b);
            if (a == 0) return {b, 0};
            
            long long s = b, t = a;
            long long m0 = 0, m1 = 1;
            
            while (t) {
                long long u = s / t;
                s -= t * u;
                m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b
                
                
                auto tmp = s;
                s = t;
                t = tmp;
                tmp = m0;
                m0 = m1;
                m1 = tmp;
            }
            if (m0 < 0) m0 += b / s;
            return {s, m0};
        }
        
        constexpr int primitive_root_constexpr(int m) {
            if (m == 2) return 1;
            if (m == 167772161) return 3;
            if (m == 469762049) return 3;
            if (m == 754974721) return 11;
            if (m == 998244353) return 3;
            int divs[20] = {};
            divs[0] = 2;
            int cnt = 1;
            int x = (m - 1) / 2;
            while (x % 2 == 0) x /= 2;
            for (int i = 3; (long long)(i)*i <= x; i += 2) {
                if (x % i == 0) {
                    divs[cnt++] = i;
                    while (x % i == 0) {
                        x /= i;
                    }
                }
            }
            if (x > 1) {
                divs[cnt++] = x;
            }
            for (int g = 2;; g++) {
                bool ok = true;
                for (int i = 0; i < cnt; i++) {
                    if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) return g;
            }
        }
        template <int m> constexpr int primitive_root = primitive_root_constexpr(m);
        
    }  // namespace internal
    
}  // namespace atcoder

#include <cassert>
#include <numeric>
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {
    
    namespace internal {
        
        struct modint_base {};
        struct static_modint_base : modint_base {};
        
        template <class T> using is_modint = std::is_base_of<modint_base, T>;
        template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
        
    }  // namespace internal
    
    template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
    struct static_modint : internal::static_modint_base {
        using mint = static_modint;
        
    public:
        static constexpr int mod() { return m; }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }
        
        static_modint() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        static_modint(T v) {
            long long x = (long long)(v % (long long)(umod()));
            if (x < 0) x += umod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        static_modint(T v) {
            _v = (unsigned int)(v % umod());
        }
        static_modint(bool v) { _v = ((unsigned int)(v) % umod()); }
        
        unsigned int val() const { return _v; }
        
        mint& operator++() {
            _v++;
            if (_v == umod()) _v = 0;
            return *this;
        }
        mint& operator--() {
            if (_v == 0) _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int) {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --*this;
            return result;
        }
        
        mint& operator+=(const mint& rhs) {
            _v += rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator-=(const mint& rhs) {
            _v -= rhs._v;
            if (_v >= umod()) _v += umod();
            return *this;
        }
        mint& operator*=(const mint& rhs) {
            unsigned long long z = _v;
            z *= rhs._v;
            _v = (unsigned int)(z % umod());
            return *this;
        }
        mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
        
        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }
        
        mint pow(long long n) const {
            assert(0 <= n);
            mint x = *this, r = 1;
            while (n) {
                if (n & 1) r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const {
            if (prime) {
                assert(_v);
                return pow(umod() - 2);
            } else {
                auto eg = internal::inv_gcd(_v, m);
                assert(eg.first == 1);
                return eg.second;
            }
        }
        
        friend mint operator+(const mint& lhs, const mint& rhs) {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint& lhs, const mint& rhs) {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint& lhs, const mint& rhs) {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint& lhs, const mint& rhs) {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint& lhs, const mint& rhs) {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint& lhs, const mint& rhs) {
            return lhs._v != rhs._v;
        }
        
    private:
        unsigned int _v;
        static constexpr unsigned int umod() { return m; }
        static constexpr bool prime = internal::is_prime<m>;
    };
    
    template <int id> struct dynamic_modint : internal::modint_base {
        using mint = dynamic_modint;
        
    public:
        static int mod() { return (int)(bt.umod()); }
        static void set_mod(int m) {
            assert(1 <= m);
            bt = internal::barrett(m);
        }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }
        
        dynamic_modint() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        dynamic_modint(T v) {
            long long x = (long long)(v % (long long)(mod()));
            if (x < 0) x += mod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        dynamic_modint(T v) {
            _v = (unsigned int)(v % mod());
        }
        dynamic_modint(bool v) { _v = ((unsigned int)(v) % mod()); }
        
        unsigned int val() const { return _v; }
        
        mint& operator++() {
            _v++;
            if (_v == umod()) _v = 0;
            return *this;
        }
        mint& operator--() {
            if (_v == 0) _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int) {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --*this;
            return result;
        }
        
        mint& operator+=(const mint& rhs) {
            _v += rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator-=(const mint& rhs) {
            _v += mod() - rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator*=(const mint& rhs) {
            _v = bt.mul(_v, rhs._v);
            return *this;
        }
        mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
        
        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }
        
        mint pow(long long n) const {
            assert(0 <= n);
            mint x = *this, r = 1;
            while (n) {
                if (n & 1) r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const {
            auto eg = internal::inv_gcd(_v, mod());
            assert(eg.first == 1);
            return eg.second;
        }
        
        friend mint operator+(const mint& lhs, const mint& rhs) {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint& lhs, const mint& rhs) {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint& lhs, const mint& rhs) {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint& lhs, const mint& rhs) {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint& lhs, const mint& rhs) {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint& lhs, const mint& rhs) {
            return lhs._v != rhs._v;
        }
        
    private:
        unsigned int _v;
        static internal::barrett bt;
        static unsigned int umod() { return bt.umod(); }
    };
    template <int id> internal::barrett dynamic_modint<id>::bt = 998244353;
    
    using modint998244353 = static_modint<998244353>;
    using modint1000000007 = static_modint<1000000007>;
    using modint3 = static_modint<3>;
    using modint = dynamic_modint<-1>;
    
    namespace internal {
        
        template <class T>
        using is_static_modint = std::is_base_of<internal::static_modint_base, T>;
        
        template <class T>
        using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
        
        template <class> struct is_dynamic_modint : public std::false_type {};
        template <int id>
        struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};
        
        template <class T>
        using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
        
    }  // namespace internal
    
}  // namespace atcoder

using mint=atcoder::modint3;

// https://nyaannyaan.github.io/library/matrix/linear-equation.hpp

#pragma once

template <typename mint>
std::pair<int, mint> GaussElimination(vector<vector<mint>> &a,
                                      int pivot_end = -1,
                                      bool diagonalize = false) {
    int H = a.size(), W = a[0].size();
    int rank = 0, je = pivot_end;
    if (je == -1) je = W;
    mint det = 1;
    for (int j = 0; j < je; j++) {
        int idx = -1;
        for (int i = rank; i < H; i++) {
            if (a[i][j] != mint(0)) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            det = 0;
            continue;
        }
        if (rank != idx) {
            det = -det;
            swap(a[rank], a[idx]);
        }
        det *= a[rank][j];
        if (diagonalize && a[rank][j] != mint(1)) {
            mint coeff = a[rank][j].inv();
            for (int k = j; k < W; k++) a[rank][k] *= coeff;
        }
        int is = diagonalize ? 0 : rank + 1;
        for (int i = is; i < H; i++) {
            if (i == rank) continue;
            if (a[i][j] != mint(0)) {
                mint coeff = a[i][j] / a[rank][j];
                for (int k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;
            }
        }
        rank++;
    }
    return make_pair(rank, det);
}

#pragma once


template <typename mint>
vector<vector<mint>> LinearEquation(vector<vector<mint>> a, vector<mint> b) {
    int H = a.size(), W = a[0].size();
    for (int i = 0; i < H; i++) a[i].push_back(b[i]);
    auto p = GaussElimination(a, W, true);
    int rank = p.first;
    
    for (int i = rank; i < H; ++i) {
        if (a[i][W] != 0) return vector<vector<mint>>{};
    }
    
    vector<vector<mint>> res(1, vector<mint>(W));
    vector<int> pivot(W, -1);
    for (int i = 0, j = 0; i < rank; ++i) {
        while (a[i][j] == 0) ++j;
        res[0][j] = a[i][W], pivot[j] = i;
    }
    for (int j = 0; j < W; ++j) {
        if (pivot[j] == -1) {
            vector<mint> x(W);
            x[j] = 1;
            for (int k = 0; k < j; ++k) {
                if (pivot[k] != -1) x[k] = -a[pivot[k]][j];
            }
            res.push_back(x);
        }
    }
    return res;
}

void solve(){
    int N,M;cin>>N>>M;
    vector<vector<int>> color(N,vector<int>(N,10));
    vector<vector<int>> S(M);
    map<pair<int,int>,int> idx;
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        if(a>b) swap(a,b);
        if(c>=1) c--;
        S[i]={a,b,c};
        color[a][b]=c;
        color[b][a]=c;
        idx[mp(a,b)]=i;
    }
    
    if(M==0){
        cout<<"\n";
        return;
    }
    
    int cn=0;
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                bool f=true;
                if(color[i][j]==10) f=false;
                if(color[i][k]==10) f=false;
                if(color[j][k]==10) f=false;
                if(f) cn++;
            }
        }
    }
    
    vector<pair<int,int>> T;
    for(int i=0;i<M;i++){
        if(S[i][2]>=0){
            T.push_back(mp(i,S[i][2]));
        }
    }
    
    if(cn+si(T)==0){
        for(int i=0;i<M;i++){
            if(S[i][2]==-1) cout<<1<<" ";
            else cout<<S[i][2]+1<<" ";
        }
        cout<<"\n";
        return;
    }
    
    vector<vector<mint>> A(cn+si(T),vector<mint>(M));
    vector<mint> B(cn+si(T));
    
    int now=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                bool f=true;
                if(color[i][j]==10) f=false;
                if(color[i][k]==10) f=false;
                if(color[j][k]==10) f=false;
                if(f){
                    A[now][idx[mp(i,j)]]=1;
                    A[now][idx[mp(i,k)]]=1;
                    A[now][idx[mp(j,k)]]=1;
                    now++;
                }
            }
        }
    }
    
    for(int i=0;i<si(T);i++){
        A[cn+i][T[i].fi]=1;
        B[cn+i]=T[i].se;
    }
    
    auto res=LinearEquation(A,B);
    
    if(si(res)==0){
        cout<<-1<<"\n";
        return;
    }
    
    for(int i=0;i<M;i++){
        cout<<res[0][i].val()+1<<" ";
    }
    cout<<"\n";
    
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        solve();
    }
}