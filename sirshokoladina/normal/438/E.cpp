#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int mod = 998244353;
const int N = 1 << 17;

struct Input {
	int k;
	int p[N];
	
	bool read () {
		int n;
		if (!(cin >> n >> k)) {
			return 0;
		}
		memset(p, 0, sizeof p);
		forn (i, n) {
			int x;
			scanf("%d", &x);
			p[x]++;
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[N];
	
	void write () {
		forn (i, k) {
			printf("%d\n", ans[i + 1]);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	
	int pw (int a, int n) {
		int res = 1;
		while (n) {
			if (n & 1) {
				res = res * 1ll * a % mod;
			}
			a = a * 1ll * a % mod;
			n >>= 1;
		}
		return res;
	}
	
	static const int L = 18;
	static const int M = 1 << L;
	
	void butterfly (ld *x, ld *y, int n) {
		for (int i = 1, j = 0; i < n; ++i) {
			int k = n >> 1;
			while (j >= k) {
				j -= k;
				k >>= 1;
			}
			j += k;
			if (i < j) {
				swap(x[i], x[j]);
				swap(y[i], y[j]);
			}
		}
	}
	
	void fft (ld *x, ld *y, int n) {
		butterfly(x, y, n);
		for (int m = 1; m < n; m <<= 1) {
			ld rx = cos(pi / m), ry = sin(pi / m);
			for (int i = 0; i < n; i += m << 1) {
				ld wx = 1, wy = 0;
				forn (j, i, i + m) {
					ld ux = x[j], uy = y[j];
					ld vx = x[j + m] * wx - y[j + m] * wy;
					ld vy = x[j + m] * wy + y[j + m] * wx;
					x[j] = ux + vx;
					y[j] = uy + vy;
					x[j + m] = ux - vx;
					y[j + m] = uy - vy;
					ld x_ = wx;
					wx = x_ * rx - wy * ry;
					wy = x_ * ry + wy * rx;
				}
			}
		}
	}
	
	void inv (ld *x, ld *y, int n) {
		forn (i, n) {
			x[i] /= n;
			y[i] /= n;
		}
		reverse(x + 1, x + n);
		reverse(y + 1, y + n);
	}
	
	static const int D = 30000;
	
	ld ax[M], ay[M], bx[M], by[M];
	ld cx[M], cy[M], dx[M], dy[M];
	
	void mult (int *a, int *b, int *res, int n) {
		forn (i, n) {
			ax[i] = a[i] % D;
			ay[i] = a[i] / D;
			bx[i] = b[i] % D;
			by[i] = b[i] / D;
		}
		memset(ax + n, 0, n * sizeof(ld));
		memset(ay + n, 0, n * sizeof(ld));
		memset(bx + n, 0, n * sizeof(ld));
		memset(by + n, 0, n * sizeof(ld));
		n <<= 1;
		fft(ax, ay, n);
		fft(bx, by, n);
		forn (i, n) {
			cx[i] = ax[i] * bx[i] - ay[i] * by[i];
			cy[i] = ax[i] * by[i] + ay[i] * bx[i];
		}
		reverse(ax + 1, ax + n);
		reverse(ay + 1, ay + n);
		forn (i, n) {
			dx[i] = ax[i] * bx[i] + ay[i] * by[i];
			dy[i] = ax[i] * by[i] - ay[i] * bx[i];
		}
		fft(cx, cy, n);
		inv(cx, cy, n);
		fft(dx, dy, n);
		inv(dx, dy, n);
		forn (i, n) {
			int p00 = ll((dx[i] + cx[i]) / 2 + 0.5) % mod;
			int p11 = ll((dx[i] - cx[i]) / 2 + 0.5) % mod;
			int p01 = ll((cy[i] + dy[i]) / 2 + 0.5) % mod;
			int p10 = ll((cy[i] - dy[i]) / 2 + 0.5) % mod;
			res[i] = (p00 + p01 * 1ll * D + p10 * 1ll * D + p11 * 1ll * D * D) % mod;
		}
	}
	
	void divide (int *a, int *res, int n) {
		static int tmp[M];
		res[0] = pw(a[0], mod - 2);
		for (int m = 1; m < n; m <<= 1) {
			mult(res, res, tmp, m);
			mult(tmp, a, tmp, m << 1);
			forn (i, m, m << 1) {
				res[i] = (mod - tmp[i]) % mod;
			}
		}
	}
	
	void sqroot (int *a, int *res, int n) {
		static int tmp[M];
		memset(res, 0, n * sizeof(int));
		res[0] = 1;
		for (int m = 1; m < n; m <<= 1) {
			divide(res, tmp, m << 1);
			mult(tmp, a, tmp, m << 1);
			forn (i, m, m << 1) {
				res[i] = tmp[i] * 1ll * (mod + 1) / 2 % mod;
			}
		}
	}
	
	void solve () {
		static int tmp[M];
		forn (i, N) {
			p[i] = p[i] * 1ll * (mod - 4) % mod;
		}
		p[0]++;
		sqroot(p, tmp, N);
		tmp[0]++;
		divide(tmp, ans, N);
		forn (i, N) {
			ans[i] = ans[i] * 2 % mod;
		}
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}