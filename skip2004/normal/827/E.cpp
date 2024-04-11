#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int mod = 7340033;
const int maxn = 1 << 20;
typedef long long ll;
int wn[maxn], rev[maxn];
inline ll pow(int a, int b, int ans = 1) {
	for(;b;b >>= 1, a = (ll) a * a % mod) if(b & 1)
		ans = (ll) ans * a % mod;
	return ans;
}

inline ll inverse(int x) {
	return pow(x, mod - 2);
}

inline void init() {
	for(int mid = 1;mid < maxn;mid <<= 1) {
		const int w = pow(3, mod / mid / 2); wn[mid] = 1;
		for(int j = 1;j < mid;++j) wn[mid + j] = (ll) wn[mid + j - 1] * w % mod;
	}
}

int lim, invlim;
inline void init(int len) {
	for(lim = 1;lim < len;lim <<= 1); invlim = mod - (mod - 1) / lim;
	for(int i = 1;i < lim;++i) rev[i] = rev[i >> 1] >> 1 | i % 2 * lim / 2;
}
inline void fft(int * a, int type) {
	for(int i = 1;i < lim;++i) if(rev[i] > i)
		std::swap(a[i], a[rev[i]]);
	for(int mid = 1;mid < lim;mid <<= 1) for(int j = 0;j < lim;j += mid + mid) for(int k = 0;k < mid;++k) {
		const int x = (ll) a[mid + j + k] * wn[mid + k] % mod;
		a[mid + j + k] = a[j + k] + mod + mod - x, a[j + k] += x;
	}
	if(!type) {
		for(int i = 0;i < lim;++i) {
			a[i] = (ll) a[i] * invlim % mod;
		}
		std::reverse(a + 1, a + lim);
	} else {
		for(int i = 0;i < lim;++i) {
			a[i] %= mod;
		}
	}
}

char s[maxn];
int n, t;

int a[maxn], b[maxn];
int yes[maxn];
int ans[maxn], tot;

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	init();
	cin >> t;
	for(int i = 0, n;i < t;++i) {
		cin >> n >> s;
		for(int i = 0;i < n;++i) {
			a[i] = s[i] == 'V';
			b[i] = s[n - i - 1] == 'K';
		}
		init(n + n);
		fft(a, 1);
		fft(b, 1);
		for(int i = 0;i < lim;++i) {
			a[i] = (ll) a[i] * b[i] % mod;
		}
		fft(a, 0);
		for(int i = 1;i < n;++i) {
			yes[i] = ! a[n - 1 - i] && !a[n - 1 + i];
		}
		for(int i = 0;i < lim;++i) {
			a[i] = b[i] = 0;
		}
		tot = 0;
		for(int i = 1;i < n;++i) {
			int ok = 1;
			for(int j = i;j < n;j += i) {
				ok = ok && yes[j];
			}
			if(ok) {
				ans[tot++] = i;
			}
		}
		ans[tot ++] = n;
		cout << tot << '\n';
		for(int i = 0;i < tot;++i) {
			cout << ans[i] << " \n"[i == tot - 1];
		}
	}
}