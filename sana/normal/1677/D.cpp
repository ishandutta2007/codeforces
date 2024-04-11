#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

#define sz(x) (int)(x).size()


typedef string str;


typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

const int MOD = 998244353;
     
    struct mod_int {
        int val;
     
        mod_int(long long v = 0) {
            if (v < 0)
                v = v % MOD + MOD;
     
            if (v >= MOD)
                v %= MOD;
     
            val = v;
        }
     
        static int mod_inv(int a, int m = MOD) {
            // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
            int g = m, r = a, x = 0, y = 1;
     
            while (r != 0) {
                int q = g / r;
                g %= r; swap(g, r);
                x -= q * y; swap(x, y);
            }
     
            return x < 0 ? x + m : x;
        }
     
        explicit operator int() const {
            return val;
        }
     
        mod_int& operator+=(const mod_int &other) {
            val += other.val;
            if (val >= MOD) val -= MOD;
            return *this;
        }
     
        mod_int& operator-=(const mod_int &other) {
            val -= other.val;
            if (val < 0) val += MOD;
            return *this;
        }
     
        static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
    #if !defined(_WIN32) || defined(_WIN64)
            return x % m;
    #endif
            // Optimized mod for Codeforces 32-bit machines.
            // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
            unsigned x_high = x >> 32, x_low = (unsigned) x;
            unsigned quot, rem;
            asm("divl %4\n"
                : "=a" (quot), "=d" (rem)
                : "d" (x_high), "a" (x_low), "r" (m));
            return rem;
        }
     
        mod_int& operator*=(const mod_int &other) {
            val = fast_mod((uint64_t) val * other.val);
            return *this;
        }
     
        
        friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
        friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
        friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
        
     
        mod_int& operator++() {
            val = val == MOD - 1 ? 0 : val + 1;
            return *this;
        }
     
        
        mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
        
     
        bool operator==(const mod_int &other) const { return val == other.val; }
        bool operator!=(const mod_int &other) const { return val != other.val; }
     
        mod_int inv() const {
            return mod_inv(val);
        }
     
        mod_int pow(long long p) const {
            assert(p >= 0);
            mod_int a = *this, result = 1;
     
            while (p > 0) {
                if (p & 1)
                    result *= a;
     
                a *= a;
                p >>= 1;
            }
     
            return result;
        }
     
        
    };
     
    vector<mod_int> inv, factorial, inv_factorial;
     
    void prepare_factorials(int maximum) {
        inv.assign(maximum + 1, 1);
     
        // Make sure MOD is prime, which is necessary for the inverse algorithm below.
        for (int p = 2; p * p <= MOD; p++)
            assert(MOD % p != 0);
     
        for (int i = 2; i <= maximum; i++)
            inv[i] = inv[MOD % i] * (MOD - MOD / i);
     
        factorial.resize(maximum + 1);
        inv_factorial.resize(maximum + 1);
        factorial[0] = inv_factorial[0] = 1;
     
        for (int i = 1; i <= maximum; i++) {
            factorial[i] = i * factorial[i - 1];
            inv_factorial[i] = inv[i] * inv_factorial[i - 1];
        }
    }
     
    
namespace NTT {
        vector<mod_int> roots = {0, 1};
        vector<int> bit_reverse;
        int max_size = -1;
        mod_int root;
     
        bool is_power_of_two(int n) {
            return (n & (n - 1)) == 0;
        }
     
        int round_up_power_two(int n) {
            assert(n > 0);
     
            while (n & (n - 1))
                n = (n | (n - 1)) + 1;
     
            return n;
        }
     
        // Given n (a power of two), finds k such that n == 1 << k.
        int get_length(int n) {
            assert(is_power_of_two(n));
            return __builtin_ctz(n);
        }
     
        // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
        // This makes even-odd div-conquer much easier.
        void bit_reorder(int n, vector<mod_int> &values) {
            if ((int) bit_reverse.size() != n) {
                bit_reverse.assign(n, 0);
                int length = get_length(n);
     
                for (int i = 0; i < n; i++)
                    bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
            }
     
            for (int i = 0; i < n; i++)
                if (i < bit_reverse[i])
                    swap(values[i], values[bit_reverse[i]]);
        }
     
        void find_root() {
            int order = MOD - 1;
            max_size = 1;
     
            while (order % 2 == 0) {
                order /= 2;
                max_size *= 2;
            }
     
            root = 2;
     
            // Find a max_size-th primitive root of MOD.
            while (!(root.pow(max_size) == 1 && root.pow(max_size / 2) != 1))
                root++;
        }
     
        void prepare_roots(int n) {
            if (max_size < 0)
                find_root();
     
            assert(n <= max_size);
     
            if ((int) roots.size() >= n)
                return;
     
            int length = get_length(roots.size());
            roots.resize(n);
     
            // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
            // the first half of the n-th primitive roots of MOD.
            while (1 << length < n) {
                // z is a 2^(length + 1)-th primitive root of MOD.
                mod_int z = root.pow(max_size >> (length + 1));
     
                for (int i = 1 << (length - 1); i < 1 << length; i++) {
                    roots[2 * i] = roots[i];
                    roots[2 * i + 1] = roots[i] * z;
                }
     
                length++;
            }
        }
     
        void fft_iterative(int N, vector<mod_int> &values) {
            assert(is_power_of_two(N));
            prepare_roots(N);
            bit_reorder(N, values);
     
            for (int n = 1; n < N; n *= 2)
                for (int start = 0; start < N; start += 2 * n)
                    for (int i = 0; i < n; i++) {
                        mod_int even = values[start + i];
                        mod_int odd = values[start + n + i] * roots[n + i];
                        values[start + n + i] = even - odd;
                        values[start + i] = even + odd;
                    }
        }
     
        const int FFT_CUTOFF = 150;
     
        vector<mod_int> mod_multiply(vector<mod_int> left, vector<mod_int> right) {
            int n = left.size();
            int m = right.size();
     
            // Brute force when either n or m is small enough.
            if (min(n, m) < FFT_CUTOFF) {
                const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
                vector<uint64_t> result(n + m - 1);
     
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++) {
                        result[i + j] += (uint64_t) ((int) left[i]) * ((int) right[j]);
     
                        if (result[i + j] > ULL_BOUND)
                            result[i + j] %= MOD;
                    }
     
                for (uint64_t &x : result)
                    if (x >= MOD)
                        x %= MOD;
     
                return vector<mod_int>(result.begin(), result.end());
            }
     
            int N = round_up_power_two(n + m - 1);
            left.resize(N);
            right.resize(N);
     
            bool equal = left == right;
            fft_iterative(N, left);
     
            if (equal)
                right = left;
            else
                fft_iterative(N, right);
     
            mod_int inv_N = mod_int(N).inv();
     
            for (int i = 0; i < N; i++)
                left[i] *= right[i] * inv_N;
     
            reverse(left.begin() + 1, left.end());
            fft_iterative(N, left);
            left.resize(n + m - 1);
            return left;
        }
     
        
    }

mod_int calc(int n, int k) {
    dbg(n,k);
    return factorial[k+1] * mod_int(k+1).pow(n-1);
}

typedef vector<mod_int> polynomial_base;


void go() {
    int n, k; cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = n-1; i >= n-k; i--) if (a[i] != 0 && a[i] != -1) {
        ps(0);
        return;
    }
    
    int z = count(a.begin(), a.begin()+(n-k), 0);
    
    auto solve = [&](auto self, int l, int r)->polynomial_base{
        if(r - l == 1) return a[l]==-1 ? polynomial_base{l, 1} : polynomial_base{1};
        int m = l + (r - l >> 1);
        return NTT::mod_multiply(self(self, l, m), self(self, m, r));
    };
    
    polynomial_base pr = solve(solve, 0, n-k);
    
    mod_int ans = 0;
    for (int az = 0; az < sz(pr); az++) {
        if (z+az>0) ans += calc(z+az, k) * pr[az];
    }
    ps( (int)ans );
}

void solve()
{
    prepare_factorials(1123456);
    
    int t;
    for (cin >> t; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}