#include<bits/stdc++.h>
const int maxn = 100100;
const int mod = 1e9 + 7;
typedef long long ll;
using std::cin;
using std::cout;
int n, ans;
int a[maxn], f[maxn];
inline ll pow(int a, int b) {
	ll ans = 1;
	for(;b;b >>= 1, a = (ll) a * a % mod) if(b & 1) {
		ans = (ll) ans * a % mod;
	}
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	int max = 0, sum = 0;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		max = std::max(max, a[i]);
		sum += a[i];
	}
	f[1] = (ll) (sum - 1) * (sum - 1) % mod * inverse(sum) % mod;
	for(int i = 2;i <= max;++i) {
		f[i] = (f[i - 1] * 2ll + mod - f[i - 2] + ll(mod - sum + 1) * inverse(sum - i + 1)) % mod;
	}
	ll ans = 0;
	for(int i = 1;i <= n;++i) ans += f[a[i]];
	cout << ans % mod << '\n';
}