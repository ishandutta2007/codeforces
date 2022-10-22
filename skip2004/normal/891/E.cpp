#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;
const int mod = 1e9 + 7;
typedef long long ll;
inline int pow(int a, int b, int ans = 1) {
	for(;b;b >>= 1, a = (ll) a * a % mod) if(b & 1)
		ans = (ll) ans * a % mod;
	return ans;
}
int n, k;
int g[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	* g = 1;
	for(int i = 1, x;i <= n;++i) {
		cin >> x;
		for(int j = i;j >= 1;--j) {
			g[j] = ((ll) g[j] * x + mod - g[j - 1]) % mod;
		}
		g[0] = (ll) g[0] * x % mod;
	}
	int mul = 1, ans = (ll) g[0] * pow(n, k) % mod;
	for(int i = 0;i <= n && i <= k;++i) {
		ans = (ans - (ll) g[i] * pow(n, k - i) % mod * mul) % mod;
		mul = (ll) mul * (k - i) % mod;
	}
	ans = (ll) ans * pow(pow(n, k), mod - 2) % mod;
	if(ans < 0) ans += mod;
	cout << ans << '\n';
}