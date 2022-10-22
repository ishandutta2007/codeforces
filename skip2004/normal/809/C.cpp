#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 1e9 + 7;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline int calc(int x, int y, int k) {
	ll ans = 0; int v = x ^ y;
	for(int i = 29;i >= 0;--i) if(x >> i & 1) {
		for(int j = 29;j >= 0;--j) if(y >> j & 1) {
			int max = std::max(i, j), p = (v ^ 1 << i ^ 1 << j) & ~((1 << max) - 1), cnt = 1 << std::min(i, j);
			if(p < k) {
				const int first = p, end = std::min(k, p + (1 << max));
				const int sum = (1ll + first + end) * (end - first) / 2 % mod;
				ans = (ans + (ll) sum * cnt) % mod;
			}
		}
	}
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	for(int i = 0;i < q;++i) {
		int x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		int ans = calc(x2, y2, k) - calc(x2, y1 - 1, k) - calc(x1 - 1, y2, k) + calc(x1 - 1, y1 - 1, k);
		cout << (unsigned) (ans + mod + mod) % mod << '\n';
	}
}