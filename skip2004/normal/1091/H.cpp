#include<bits/stdc++.h>
const int maxn = 1 << 20;
using std::cin;
using std::cout;
int is[maxn], can[maxn];
int n, f;
std::vector<int> vec;
int sg[maxn], notsure[maxn];
namespace poly {

	typedef long long ll;
	typedef unsigned long long u64, ull;
	typedef unsigned u32;

	const int maxn = 1 << 20;
	const int mod = 7340033;
	inline ll pow(ll a,int b,ll ans = 1){ for(;b;b >>= 1, a = a * a % mod) if(b & 1) ans = ans * a % mod; return ans; }
	inline ll inverse(ll x){ return pow(x, mod - 2); }
	int wn[maxn], rev[maxn << 1], inv[maxn], lim, invlim;
	u32 iwn[maxn];
	inline u32 getinv(u32 x) {
		return ((u64) x << 32) / mod;
	}
	inline void init_(int n) {
		int N = 1; for(;N < n;) N <<= 1;
		for(int i = 1;i < N;i <<= 1) {
			const int w = pow(3, mod / i / 2);
			wn[i] = 1; iwn[i] = getinv(wn[i]);
			for(int j = 1;j < i;++j) {
				wn[i + j] = (ll) wn[i + j - 1] * w % mod;
				iwn[i + j] = getinv(wn[i + j]);
			}
		}
		for(int i = 1;i <= N;i <<= 1) {
			for(int j = 1;j < i;++j) rev[i + j] = rev[i + (j >> 1)] >> 1 | j % 2 * i / 2;
		}
	}
	inline void init(int len) {
		lim = len; invlim = mod - (mod - 1) / lim;
	}
	inline void reduce(int & x) {
		x += x >> 31 & mod;
	}
	static u32 t[maxn];
	inline void fft(int * a,int type) {
#define trans(i, j, k) \
		{ \
			const u32 x = wn[i + k] * t[i + j + k] - u32((u64) iwn[i + k] * t[i + j + k] >> 32) * mod; \
			t[i + j + k] = t[j + k] + mod + mod - x, t[j + k] += x; \
		}
		for(int i = 0;i < lim;++i) t[i] = a[rev[lim + i]];
		for(int i = 1;i < lim;i <<= 1) {
			if(i == 1) {
				for(int j = 0;j < lim;j += 8) {
					trans(1, j, 0);
					trans(1, j + 2, 0);
					trans(1, j + 4, 0);
					trans(1, j + 6, 0);
				}
			} else if(i == 2) {
				for(int j = 0;j < lim;j += 8) {
					trans(2, j, 0);
					trans(2, j, 1);
					trans(2, j + 4, 0);
					trans(2, j + 4, 1);
				}
			} else {
				for(int j = 0;j < lim;j += i + i) for(int k = 0;k < i;k += 4) {
					trans(i, j, k + 0);
					trans(i, j, k + 1);
					trans(i, j, k + 2);
					trans(i, j, k + 3);
				}
			}
		}
		if(type == 1) {
			for(int i = 0;i < lim;++i) a[i] = t[i] % mod;
		}
		if(type == 0) {
			a[0] = (u64) t[0] * invlim % mod;
			for(int i = 1;i < lim;++i) a[i] = (u64) t[lim - i] * invlim % mod;
		}
	}
	inline void fill(int * a, const int * b, int len) {
		memcpy(a, b, len << 2), memset(a + len, 0, lim - len << 2);
	}
	typedef std::function<int(int, int*)> fc;
	struct solver {
		static const int C = 64;
		static const int B = 32;
		int n, N;
		int rem[maxn], g[maxn], * MM;

		int M[B][(maxn << 1) / B];
		u64 g0[maxn << 2];
		inline void Init(int len, int * multi) {
			MM = multi;
			for(n = len, N = 1;N < len;N <<= 1);
			for(int mid = (N + N) / B;mid > 1;mid /= B) {
				init(mid); 
				for(int j = 0;j + 1 < B;++j) {
					if(j * mid / 2 < n) {
						for(int i = 0;i < mid;++i) M[j][mid + i] = MM[i + j * mid / 2];
						fft(M[j] + mid, 1);
					}
				}
			}
		}
		inline void solve(int l, int r, u64 * g0, const fc & xxx) {
			if(r - l < C) {
				for(int i = l;i < r;++i) {
					int j = l;
					u64 x = rem[i];
#define T(o) (u64) g[j + o] * MM[i - j - o]
					for(;j + 15 < i;j += 16) {
						x = (x + T(0) + T(1) + T(2) + T(3) + T(4) + T(5) + T(6) + T(7) + 
								T(8) + T(9) + T(10) + T(11) + T(12) + T(13) + T(14) + T(15)) % mod;
					}
					if(j != i) {
						for(;j < i;++j) x += T(0);
						x %= mod;
					}
#undef T
					rem[i] = x;
					g[i] = xxx(i, rem + i);
				}
				return ;
			}
			const int DT = (r - l) / B;
			if(l) memset(g0, 0, r - l << 4);
			int end = 0;
			for(;end < B && l + end * DT < n;++end);
			for(int i = 0;i < end;++i) {
				int L = l + i * DT, R = L + DT;
				if(std::find(notsure + L, notsure + R, 1) == notsure + R) continue;
				if(i) {
					static int T[maxn];
					init(DT + DT);
					for(int j = 0;j < lim;++j) T[j] = g0[2 * i * DT + j] % mod;
					fft(T, 2);
					for(int j = L;j < R;++j) rem[j] = (rem[j] + (ll) invlim * t[lim - j + L - DT]) % mod;
				}
				solve(L, R, g0 + (r - l << 1), xxx);
				if(i != end - 1 && std::find_if(g + L, g + R, [](u32 x) -> bool { return x; }) != g + R) {
					init(DT + DT);
					static int b[maxn];
					fill(b, g + L, R - L), fft(b, 1);
					for(int j = i + 1;j < end;++j) {
						ull * g1 = g0 + lim * j;
						for(int k = 0;k < lim;++k) {
							g1[k] += (ll) b[k] * M[j - i - 1][lim + k];
						}
					}
				}
			}
		}
		inline void solve(fc x) { solve(0, N, g0, x); }
	};
}
poly::solver solver, dak;
inline void init() {
	const int n = 2e5;
	poly::init_(1 << 20);
	for(int i = 2;i <= n;++i) if(!is[i]) {
		for(int j = i + i;j <= n;j += i) {
			is[j] = 1;
		}
	}
	for(int i = 2;i <= n;++i) if(!is[i]) {
		can[i] = 1;
		for(int j = 2;j * i <= n;++j) if(!is[j]) {
			can[i * j] = 1;
		}
	}
	can[f] = 0;
	dak.Init(n, can);
	for(int i = 0;i < n;++i) {
		sg[i] = -1;
	}
	for(int i = 0;;++i) {
		solver = dak;
		int any = 0;
		for(int i = 0;i < n;++i) {
			any += notsure[i] = sg[i] == -1;
		}
		if(!any) break;
		solver.solve([&](int pos, int*now) {
			if(notsure[pos] && !*now) {
				sg[pos] = i;
				return 1;
			}
			return 0;
		});
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> f;
	init();
	int all = 0;
	for(int i = 0;i < n;++i) {
		int a, b, c;
		cin >> a >> b >> c;
		all ^= sg[b - a - 1];
		all ^= sg[c - b - 1];
	}
	if(all) cout << "Alice" << '\n';
	cout << "Bob" << '\n';
	if(!all) cout << "Alice" << '\n';
}