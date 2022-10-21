#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

//#define FFT false

namespace fft {
#if FFT
    // FFT
using dbl = double;
struct num { /// start-hash
	dbl x, y;
	num(dbl x_ = 0, dbl y_ = 0) : x(x_), y(y_) { }
};
inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline num conj(num a) { return num(a.x, -a.y); }
inline num inv(num a) { dbl n = (a.x*a.x+a.y*a.y); return num(a.x/n,-a.y/n); }
/// end-hash
#else
// NTT
    const int mod = 998244353, g = 3;
// For p < 2^30 there is also (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). Last two are > 10^9.
    struct num { /// start-hash
        int v;
        num(ll v_ = 0) : v(int(v_ % mod)) { if (v<0) v+=mod; }
        explicit operator int() const { return v; }
    };
    inline num operator+(num a,num b){return num(a.v+b.v);}
    inline num operator-(num a,num b){return num(a.v+mod-b.v);}
    inline num operator*(num a,num b){return num(1ll*a.v*b.v);}
    inline num pow(num a, int b) {
        num r = 1;
        do{if(b&1)r=r*a;a=a*a;}while(b>>=1);
        return r;
    }
    inline num inv(num a) { return pow(a, mod-2); }
/// end-hash
#endif

    using vn = vector<num>;
    vi rev({0, 1});
    vn rt(2, num(1)), fa, fb;

    inline void init(int n) { /// start-hash
        if (n <= sz(rt)) return;
        rev.resize(n);
        rep(i,0,n) rev[i] = (rev[i>>1] | ((i&1)*n)) >> 1;
        rt.reserve(n);
        for (int k = sz(rt); k < n; k *= 2) {
            rt.resize(2*k);
#if FFT
            double a=M_PI/k; num z(cos(a),sin(a)); // FFT
#else
            num z = pow(num(g), (mod-1)/(2*k)); // NTT
#endif
            rep(i,k/2,k) rt[2*i] = rt[i], rt[2*i+1] = rt[i]*z;
        }
    } /// end-hash

    inline void fft(vector<num> &a, int n) { /// start-hash
        init(n);
        int s = __builtin_ctz(sz(rev)/n);
        rep(i,0,n) if (i < rev[i]>>s) swap(a[i], a[rev[i]>>s]);
        for (int k = 1; k < n; k *= 2)
            for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
                    num t = rt[j+k] * a[i+j+k];
                    a[i+j+k] = a[i+j] - t;
                    a[i+j] = a[i+j] + t;
                }
    } /// end-hash

// Complex/NTT
    vn multiply(vn a, vn b) { /// start-hash
        int s = sz(a) + sz(b) - 1;
        if (s <= 0) return {};
        int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
        a.resize(n), b.resize(n);
        fft(a, n);
        fft(b, n);
        num d = inv(num(n));
        rep(i,0,n) a[i] = a[i] * b[i] * d;
        reverse(a.begin()+1, a.end());
        fft(a, n);
        a.resize(s);
        return a;
    } /// end-hash

    vn fast_pow(vn a, int k) {
        int s = (sz(a) - 1) * k + 1;
        if (s <= 0) return {};
        int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
        a.resize(n);
        fft(a, n);
        num d = inv(num(n));
        rep(i,0,n) a[i] = pow(a[i], k) * d;
        reverse(a.begin()+1, a.end());
        fft(a, n);
        a.resize(s);
        return a;
    }
}

const int mod = 998244353;
int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    fft::vn a(10);
    rep(i, 0, k) {
        int x; cin >> x;
        a[x].v = 1;
    }
    fft::vn x = fft::fast_pow(a, n / 2);

    ll res = 0;
    for(int i = 0; i < sz(x); i++) {
        res = (res + (x[i] * x[i]).v) % mod;
    }
    cout << res << endl;



}