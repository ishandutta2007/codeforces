#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

# define M_PI  3.14159265358979323846 /* pi */


typedef double DOUBLE;
typedef complex<DOUBLE> COMPLEX;
typedef vector<DOUBLE> VD;
typedef vector<COMPLEX> VC;

struct FFT {
  VC A;
  int n, L;

  int ReverseBits(int k) {
    int ret = 0;
    for (int i = 0; i < L; i++) {
      ret = (ret << 1) | (k & 1);
      k >>= 1;
    }
    return ret;
  }

  void BitReverseCopy(VC a) {
    for (n = 1, L = 0; n < a.size(); n <<= 1, L++) ;
    A.resize(n);
    for (int k = 0; k < n; k++) 
      A[ReverseBits(k)] = a[k];
  }
  
  VC DFT(VC a, bool inverse) {
    BitReverseCopy(a);
    for (int s = 1; s <= L; s++) {
      int m = 1 << s;
      COMPLEX wm = exp(COMPLEX(0, 2.0 * M_PI / m));
      if (inverse) wm = COMPLEX(1, 0) / wm;
      for (int k = 0; k < n; k += m) {
	COMPLEX w = 1;
	for (int j = 0; j < m/2; j++) {
	  COMPLEX t = w * A[k + j + m/2];
	  COMPLEX u = A[k + j];
	  A[k + j] = u + t;
	  A[k + j + m/2] = u - t;
	  w = w * wm;
	}
      }
    }
    if (inverse) for (int i = 0; i < n; i++) A[i] /= n;
    return A;
  }

  // c[k] = sum_{i=0}^k a[i] b[k-i]
  VD Convolution(VD a, VD b) {
	if (sz(a)+sz(b) <= 200) {
		int s = sz(a) + sz(b) - 1;
		VD c(s);
		rep(i,0,sz(a)) rep(j,0,sz(b))
			c[i + j] += a[i] * b[j];
		return c;
	}

    int L = 1;
    while ((1 << L) < a.size()) L++;
    while ((1 << L) < b.size()) L++;
    int n = 1 << (L+1);

    VC aa, bb;
    for (size_t i = 0; i < n; i++) aa.push_back(i < a.size() ? COMPLEX(a[i], 0) : 0);
    for (size_t i = 0; i < n; i++) bb.push_back(i < b.size() ? COMPLEX(b[i], 0) : 0);
    
    VC AA = DFT(aa, false);
    VC BB = DFT(bb, false);
    VC CC;
    for (size_t i = 0; i < AA.size(); i++) CC.push_back(AA[i] * BB[i]);
    VC cc = DFT(CC, true);

    VD c;
    for (int i = 0; i < a.size() + b.size() - 1; i++) c.push_back(cc[i].real());
    return c;
  }

};

/*
const ll mod = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}

typedef vector<ll> vl;
void ntt(ll* x, ll* temp, ll* roots, int N, int skip) {
	if (N == 1) return;
	int n2 = N/2;
	ntt(x     , temp, roots, n2, skip*2);
	ntt(x+skip, temp, roots, n2, skip*2);
	rep(i,0,N) temp[i] = x[i*skip];
	rep(i,0,n2) {
		ll s = temp[2*i], t = temp[2*i+1] * roots[skip*i];
		x[skip*i] = (s + t) % mod; x[skip*(i+n2)] = (s - t) % mod;
	}
}
void ntt(vl& x, bool inv = false) {
	ll e = modpow(root, (mod-1) / sz(x));
	if (inv) e = modpow(e, mod-2);
	vl roots(sz(x), 1), temp = roots;
	rep(i,1,sz(x)) roots[i] = roots[i-1] * e % mod;
	ntt(&x[0], &temp[0], &roots[0], sz(x), 1);
}
vl conv(vl a, vl b) {
	int s = sz(a) + sz(b) - 1; if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
	if (s <= 200) { // (factor 10 optimization for |a|,|b| = 10)
		vl c(s);
		rep(i,0,sz(a)) rep(j,0,sz(b))
			c[i + j] = (c[i + j] + a[i] * b[j]) % mod;
		return c;
	}
	a.resize(n); ntt(a);
	b.resize(n); ntt(b);
	vl c(n); ll d = modpow(n, mod-2);
	rep(i,0,n) c[i] = a[i] * b[i] % mod * d % mod;
	ntt(c, true); c.resize(s); return c;
}
*/

void solve() {
	int N;
	cin >> N;
	string str;
	cin >> str;
	int M = N * 2+3;
	VD a(M), b(M);
	rep(i,0,N) {
		if (str[i] == 'V') a[i] = 1;
		if (str[i] == 'K') b[N-1-i] = 1;
	}
	FFT fft;
	VD c = fft.Convolution(a, b);
	vi has(N+5);
	rep(i,0,M) {
		if (c[i] > 0.5) {
			int d = i - (N-1);
			assert(d);
			has[abs(d)] = 1;
		}
	}

	vi res;
	rep(i,1,N+1) {
		int h = 0;
		for (int j = i; j <= N; j += i) if (has[j]) { h = 1; break; }
		if (!h) res.push_back(i);
	}
	cout << sz(res) << endl;
	trav(i, res)
		cout << i << ' ';
	cout << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	rep(i,0,N) solve();
	exit(0);
}