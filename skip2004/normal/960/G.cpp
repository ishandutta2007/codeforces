#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 1 << 19;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int wn[maxn], rev[maxn], lim, invlim;
inline void init() {
	for(int mid = 1;mid < maxn;mid <<= 1) {
		const int W = pow(3, mod / 2 / mid); wn[mid] = 1;
		for(int i = 1;i < mid;++i) wn[i + mid] = (ll) wn[i + mid - 1] * W % mod;
	}
}
inline void init(int len) {
	for(lim = 1;lim < len;lim <<= 1); invlim = mod - (mod - 1) / lim;
	for(int i = 1;i < lim;++i) rev[i] = rev[i >> 1] >> 1 | (i % 2 * lim / 2);
}
inline void fft(int * a, int type) {
	typedef unsigned long long u64;
	static u64 t[maxn];
	for(int i = 0;i < lim;++i) t[i] = a[rev[i]];
	for(int mid = 1;mid < lim;mid <<= 1) {
		for(int j = 0;j < lim;j += mid + mid) {
			for(int k = 0;k < mid;++k) {
				const u64 x = t[mid + j + k] * wn[mid + k] % mod;
				t[mid + j + k] = t[j + k] + mod - x, t[j + k] += x;
			}
		}
	}
	for(int i = 0;i < lim;++i) a[i] = t[i] % mod;
	if(!type) {
		std::reverse(a + 1, a + lim);
		for(int i = 0;i < lim;++i) a[i] = (ll) a[i] * invlim % mod;
	}
}
int n, a, b;
std::vector<int> conv(const std::vector<int> & a, const std::vector<int> & b) {
	static int A[maxn], B[maxn];
	init(a.size() + b.size() - 1);
	for(int i = 0;i < (int) a.size();++i) A[i] = a[i];
	for(int i = a.size();i < lim;++i) A[i] = 0;
	for(int i = 0;i < (int) b.size();++i) B[i] = b[i];
	for(int i = b.size();i < lim;++i) B[i] = 0;
	fft(A, 1), fft(B, 1);
	for(int i = 0;i < lim;++i) A[i] = (ll) A[i] * B[i] % mod;
	fft(A, 0);
	return std::vector<int>(A, A + a.size() + b.size() - 1);
}
inline std::vector<int> solve(int l, int r) {
	if(l + 1 == r) return {l, 1};
	int mid = l + r >> 1;
	return conv(solve(l, mid), solve(mid, r));
}
inline ll fac(int x) { return x ? fac(x - 1) * x % mod : 1; }
inline ll ifac(int x) { return inverse(fac(x)); }
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> a >> b, init();
	if(!a || !b) {
		cout << 0 << '\n';
		return 0;
	}
	std::vector<int> G = n != 1 ? solve(0, n - 1) : std::vector<int>{1};
	int ans = a + b - 2 < G.size() ? G[a + b - 2] : 0;
	cout << int(ans * fac(a + b - 2) % mod * ifac(a - 1) % mod * ifac(b - 1) % mod) << '\n';
}