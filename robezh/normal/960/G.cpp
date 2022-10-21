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

// For multiply_mod, use num = modnum, poly = vector<num>
using fft::num;
using poly = fft::vn;
using fft::multiply;
using fft::inverse;
/// start-hash
poly& operator+=(poly& a, const poly& b) {
    if (sz(a) < sz(b)) a.resize(b.size());
    rep(i,0,sz(b)) a[i]=a[i]+b[i];
    return a;
}
poly operator+(const poly& a, const poly& b) { poly r=a; r+=b; return r; }
poly& operator-=(poly& a, const poly& b) {
    if (sz(a) < sz(b)) a.resize(b.size());
    rep(i,0,sz(b)) a[i]=a[i]-b[i];
    return a;
}
poly operator-(const poly& a, const poly& b) { poly r=a; r-=b; return r; }
poly operator*(const poly& a, const poly& b) {
    // TODO: small-case?
    return multiply(a, b);
}
poly& operator*=(poly& a, const poly& b) {return a = a*b;}
/// end-hash
poly& operator*=(poly& a, const num& b) { // Optional
    trav(x, a) x = x * b;
    return a;
}
poly operator*(const poly& a, const num& b) { poly r=a; r*=b; return r; }

// Polynomial floor division; no leading 0's plz
poly operator/(poly a, poly b) { /// start-hash
    if (sz(a) < sz(b)) return {};
    int s = sz(a)-sz(b)+1;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a.resize(s);
    b.resize(s);
    a = a * inverse(move(b));
    a.resize(s);
    reverse(a.begin(), a.end());
    return a;
} /// end-hash
poly& operator/=(poly& a, const poly& b) {return a = a/b;}
poly& operator%=(poly& a, const poly& b) { /// start-hash
    if (sz(a) >= sz(b)) {
        poly c = (a / b) * b;
        a.resize(sz(b)-1);
        rep(i,0,sz(a)) a[i] = a[i]-c[i];
    }
    return a;
} /// end-hash
poly operator%(const poly& a, const poly& b) { poly r=a; r%=b; return r; }

// Log/exp/pow
poly deriv(const poly& a) { /// start-hash
    if (a.empty()) return {};
    poly b(sz(a)-1);
    rep(i,1,sz(a)) b[i-1]=a[i]*i;
    return b;
} /// end-hash
poly integ(const poly& a) { /// start-hash
    poly b(sz(a)+1);
    b[1]=1; // mod p
    rep(i,2,sz(b)) b[i]=b[fft::mod%i]*(-fft::mod/i); // mod p
    rep(i,1,sz(b)) b[i]=a[i-1]*b[i]; // mod p
    //rep(i,1,sz(b)) b[i]=a[i-1]*inv(num(i)); // else
    return b;
} /// end-hash
poly log(const poly& a) { // a[0] == 1 /// start-hash
    poly b = integ(deriv(a)*inverse(a));
    b.resize(a.size());
    return b;
} /// end-hash
poly exp(const poly& a) { // a[0] == 0 /// start-hash
    poly b(1,num(1));
    if (a.empty()) return b;
    while (sz(b) < sz(a)) {
        int n = min(sz(b) * 2, sz(a));
        b.resize(n);
        poly v = poly(a.begin(), a.begin() + n) - log(b);
        v[0] = v[0]+num(1);
        b *= v;
        b.resize(n);
    }
    return b;
} /// end-hash
poly pow(const poly& a, int m) { // m >= 0 /// start-hash
    poly b(a.size());
    if (!m) { b[0] = 1; return b; }
    int p = 0;
    while (p<sz(a) && a[p].v==0) ++p;
    if (1ll*m*p >= sz(a)) return b;
    num mu = pow(a[p], m), di = inv(a[p]);
    poly c(sz(a) - m*p);
    rep(i,0,sz(c)) c[i] = a[i+p] * di;
    c = log(c);
    trav(v,c) v = v * m;
    c = exp(c);
    rep(i,0,sz(c)) b[i+m*p] = c[i] * mu;
    return b;
}

poly solve(int l, int r) {
    if(l == r) {
        if(l == 1) return {0, 1};
        else {
            return {(l - 2), 1};
        }
    }
    int mid = (l + r) / 2;
    return solve(l, mid) * solve(mid + 1, r);
}

const int N = (int)1e5 + 50;

num C(int n, int k) {
    num res = 1;
    for (int i = n; i > n - k; i--) res = res * num(i);
    for (int i = 1; i <= k; i++) res = res * inv(num(i));
    return res;
}

num fac(int n) {
    num res = 1;
    for (int i = n; i >= 1; i--) res = res * num(i);
    return res;
}
int n, a, b;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;
    if(a + b - 1 > n || a == 0 || b == 0) return cout << 0 << '\n', 0;
    poly p = solve(1, n);
//    cout << int(p[a + b - 1]) << endl;
    num res = C(a + b - 2, b - 1) * p[a + b - 1];
    cout << int(res) << '\n';

}