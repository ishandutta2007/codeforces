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
#define M_PI		3.14159265358979323846

const int N = (int)1e6 + 50;

typedef bitset<N> bs;

bs has;
bs vis;
int n, m;
vi rs;

#define FFT true

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

// Complex/NTT power-series inverse
// Doubles b as b[:n] = (2 - a[:n] * b[:n/2]) * b[:n/2]
    vn inverse(const vn& a) { /// start-hash
        if (a.empty()) return {};
        vn b({inv(a[0])});
        b.reserve(2*a.size());
        while (sz(b) < sz(a)) {
            int n = 2*sz(b);
            b.resize(2*n, 0);
            if (sz(fa) < 2*n) fa.resize(2*n);
            fill(fa.begin(), fa.begin()+2*n, 0);
            copy(a.begin(), a.begin()+min(n,sz(a)), fa.begin());
            fft(b, 2*n);
            fft(fa, 2*n);
            num d = inv(num(2*n));
            rep(i, 0, 2*n) b[i] = b[i] * (2 - fa[i] * b[i]) * d;
            reverse(b.begin()+1, b.end());
            fft(b, 2*n);
            b.resize(n);
        }
        b.resize(a.size());
        return b;
    } /// end-hash

#if FFT
    // Double multiply (num = complex)
using vd = vector<double>;
vd multiply(const vd& a, const vd& b) { /// start-hash
	int s = sz(a) + sz(b) - 1;
	if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
	if (sz(fa) < n) fa.resize(n);
	if (sz(fb) < n) fb.resize(n);

	fill(fa.begin(), fa.begin() + n, 0);
	rep(i,0,sz(a)) fa[i].x = a[i];
	rep(i,0,sz(b)) fa[i].y = b[i];
	fft(fa, n);
	trav(x, fa) x = x * x;
	rep(i,0,n) fb[i] = fa[(n-i)&(n-1)] - conj(fa[i]);
	fft(fb, n);
	vd r(s);
	rep(i,0,s) r[i] = fb[i].y / (4*n);
	return r;
} /// end-hash

// Integer multiply mod m (num = complex) /// start-hash
vi multiply_mod(const vi& a, const vi& b, int m) {
	int s = sz(a) + sz(b) - 1;
	if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
	if (sz(fa) < n) fa.resize(n);
	if (sz(fb) < n) fb.resize(n);

	rep(i,0,sz(a)) fa[i] = num(a[i] & ((1<<15)-1), a[i] >> 15);
	fill(fa.begin()+sz(a), fa.begin() + n, 0);
	rep(i,0,sz(b)) fb[i] = num(b[i] & ((1<<15)-1), b[i] >> 15);
	fill(fb.begin()+sz(b), fb.begin() + n, 0);

	fft(fa, n);
	fft(fb, n);
	double r0 = 0.5 / n; // 1/2n
	rep(i,0,n/2+1) {
		int j = (n-i)&(n-1);
		num g0 = (fb[i] + conj(fb[j])) * r0;
		num g1 = (fb[i] - conj(fb[j])) * r0;
		swap(g1.x, g1.y); g1.y *= -1;
		if (j != i) {
			swap(fa[j], fa[i]);
			fb[j] = fa[j] * g1;
			fa[j] = fa[j] * g0;
		}
		fb[i] = fa[i] * conj(g1);
		fa[i] = fa[i] * conj(g0);
	}
	fft(fa, n);
	fft(fb, n);
	vi r(s);
	rep(i,0,s) r[i] = int((ll(fa[i].x+0.5)
				+ (ll(fa[i].y+0.5) % m << 15)
				+ (ll(fb[i].x+0.5) % m << 15)
				+ (ll(fb[i].y+0.5) % m << 30)) % m);
	return r;
} /// end-hash
#endif

} // namespace fft

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    fft::vn vs;
    rep(i, 0, n) {
        int x; cin >> x;
        has[x] = 1;
    }
    rep(i, 0, m + 1) {
        vs.push_back(fft::num(has[i]));
    }
    fft::vn v2s = fft::multiply(vs, vs);
    vi res;
    rep(i, 1, m + 1) {
        int h0 = has[i], h1 = v2s[i].x > 0.5;
//        if(i == 2) cout << h0 << " " << h1 << endl;
        if(h0 && !h1) {
            res.push_back(i);
        } else if(!h0 && h1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    cout << sz(res) << '\n';
    for (int x : res) cout << x << " ";
    cout << '\n';


}