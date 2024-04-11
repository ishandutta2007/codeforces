#include<vector>
#include<set>
#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;
using u64 = unsigned long long;

const int N = 200005;
const int mod = 998244353;
int fac[N], ifac[N], inv[N];
int n, m;
int s[N], t[N];

int w = 1;
int cnt[N], sum;
inline void inc(int x) {
	w = (u64) w * ++sum % mod;
	w = (u64) w * inv[++cnt[x]] % mod;
}
inline void dec(int x) {
	w = (u64) w * inv[sum--] % mod;
	w = (u64) w * cnt[x]-- % mod;
}
struct bit {
	int a[N];
	inline void add(int x, int v) {
		for(;x < N;x += x & -x) {
			a[x] = (a[x] + v) % mod;
		}
	}
	inline int qry(int x) {
		int ans = 0;
		for(;x;x &= x - 1) {
			ans = (ans + a[x]) % mod;
		}
		return ans;
	}
} b0;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	*fac = *ifac = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2;i < N;++i) {
		fac[i] = (u64) fac[i - 1] * i % mod;
		inv[i] = inv[mod % i] * u64(mod - mod / i) % mod;
		ifac[i] = (u64) ifac[i - 1] * inv[i] % mod;
	}
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> s[i], inc(s[i]);
	for(int i = 1;i <= m;++i) cin >> t[i];
	u64 ans = 0;
	if(m > n) {
		ans += std::multiset<int>(s + 1, s + n + 1) == std::multiset<int>(t + 1, t + n + 1);
	}
	const int V = *std::max_element(s + 1, s + n + 1);
	for(int i = 1;i <= V;++i) b0.add(i, cnt[i]);
	for(int lcp = 1;lcp <= std::min(n, m);++lcp) {
		ans = (ans + (u64) w * inv[sum] % mod * b0.qry(t[lcp] - 1)) % mod;
		if(!cnt[t[lcp]]) break;
		b0.add(t[lcp], mod-1);
		dec(t[lcp]);
	}
	cout << ans << '\n';
}