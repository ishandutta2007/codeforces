#include<cstdio>
#include<iostream>
#include<algorithm>
typedef unsigned long long u64;
typedef unsigned u32;
const int mod = 490019;
const int maxn = 1 << 20;
const u32 mod1 = 69206017, Tmod1 = mod1 + mod1;
const u32 mod2 = 81788929, Tmod2 = mod2 + mod2;

inline u64 pow(u64 a, int b, const int mod, u64 ans = 1) {
	for(;b;b >>= 1, a = a * a % mod) if(b & 1) 
		ans = ans * a % mod;
	return ans;
}

namespace poly {
	struct integer {
		u32 a, b;
		inline integer operator * (const integer & x) const {
			return (integer){u32((u64) a * x.a % mod1), u32((u64) b * x.b % mod2)};
		}
	};
	inline u64 get(const integer & x) {
		static const u32 i12 = pow(mod1, mod2 - 2, mod2);
		return u64(x.b + mod2 - x.a) * i12 % mod2 * mod1 + x.a;
	}
	const integer E = {1, 1}, Z = {0, 0};
	integer wn[maxn], invwn[maxn], invlim;
	int rev[maxn], lim;
	inline integer inverse(const integer&x) {
		return (integer){ u32(((u64) x.a << 32) / mod1), u32(((u64) x.b << 32) / mod2) };
	}
	inline void init() {
		const int mid = maxn / 2;
		const integer w = {u32(pow(7, mod1 / maxn, mod1)), u32(pow(7, mod2 / maxn, mod2))};
		wn[mid] = E; invwn[mid] = inverse(E);
		for(int i = 1;i < mid;++i) {
			wn[i + mid] = wn[i + mid - 1] * w;
			invwn[i + mid] = inverse(wn[i + mid]);
		}
		for(int i = mid - 1;i >= 1;--i) {
			wn[i] = wn[i << 1];
			invwn[i] = invwn[i << 1];
		}
	}
	inline void init(int len) {
		for(lim = 1;lim < len;lim <<= 1);
		invlim = {u32(mod1 - (mod1 - 1) / lim), u32(mod2 - (mod2 - 1) / lim)};
		for(int i = 1;i < lim;++i) {
			rev[i] = rev[i >> 1] >> 1 | i % 2 * lim / 2;
		}
	}
	inline void fft(integer * a, int type) {
		for(int i = 1;i < lim;++i) if(rev[i] > i) {
			std::swap(a[i], a[rev[i]]);
		}
		for(int mid = 1;mid < lim;mid <<= 1) {
			for(int j = 0;j < lim;j += mid + mid) {
				for(int k = 0;k < mid;++k) {
					const u32 x1 = a[mid + j + k].a * wn[mid + k].a - u32((u64) a[mid + j + k].a * invwn[mid + k].a >> 32) * mod1;
					const u32 x2 = a[mid + j + k].b * wn[mid + k].b - u32((u64) a[mid + j + k].b * invwn[mid + k].b >> 32) * mod2;
					a[mid + j + k].a = a[j + k].a + mod1 + mod1 - x1;
					a[mid + j + k].b = a[j + k].b + mod2 + mod2 - x2;
					a[j + k].a += x1;
					a[j + k].b += x2;
				}
			}
		}
		if(!type) {
			for(int i = 0;i < lim;++i) {
				a[i] = a[i] * invlim;
			}
			std::reverse(a + 1, a + lim);
		}
	}
}

int n, m, c, ic;
int a[maxn], b[maxn];
int pw[maxn], ipw[maxn];

static poly::integer A[maxn], B[maxn];
int main() {
	poly::init();
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	using std::cin;
	using std::cout;
	cin >> n >> m >> c, ic = pow(c, mod - 2, mod);
	for(int i = 0, x;i < n;++i) cin >> x, a[(u64) i * i % (mod - 1)] += x;
	for(int i = 0, x;i < m;++i) cin >> x, b[(u64) i * i * i % (mod - 1)] += x;
	*pw = *ipw = 1;
	for(int i = 1;i < maxn;++i) {
		pw[i] = (u64) pw[i - 1] * c % mod;
		ipw[i] = (u64) ipw[i - 1] * ic % mod;
	}
	poly::init(1 << 20);
	for(int i = 0;i < mod;++i) {
		a[i] = (u64) a[i] * ipw[(u64) i * (i - 1) / 2 % (mod - 1)] % mod;
		b[i] = (u64) b[i] * ipw[(u64) i * (i - 1) / 2 % (mod - 1)] % mod;
		A[i] = (poly::integer) { (u32) (a[i] + mod1) % mod1, (u32) (a[i] + mod2) % mod2 };
		B[i] = (poly::integer) { (u32) (b[i] + mod1) % mod1, (u32) (b[i] + mod2) % mod2 };
	}
	poly::fft(A, 1);
	poly::fft(B, 1);
	for(int i = 0;i < poly::lim;++i) A[i] = A[i] * B[i];
	poly::fft(A, 0);
	u64 ans = 0;
	for(int i = 0;i < poly::lim;++i) {
		u64 x = poly::get(A[i]) % mod;
		ans = (ans + x * pw[(u64) i * (i - 1) / 2 % (mod - 1)]) % mod;
	}
	cout << ans << '\n';
}