#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using std::cin;
using std::cout;
typedef long long ll;
const int maxn = 200100;
int n, k;
inline ll pow(int a, int b, int ans = 1) {
	for(;b;b >>= 1, a = (ll) a * a % mod) if(b & 1) {
		ans = (ll) ans * a % mod;
	}
	return ans;
}
int val[maxn];
int cnt[maxn];
int d[maxn];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> k;
	-- n;
	ll ans = 0;
	for(int gcd = 1;gcd <= n;++gcd) {
		const int N = n / gcd;
		for(int i = 1;i <= N;++i) d[i] = 0;
		d[1] = 1;
		for(int i = 1;i <= N;++i) {
			for(int j = i + i;j <= N;j += i) d[j] -= d[i];
			const int M = N / i;
			for(int j = 2;j <= M + M;++j) {
				cnt[i * j] += (j <= M ? j - 1 : M + M - j + 1) * d[i];
			}
		}
		for(int i = 2;i <= N * 2;++i) {
			ans = (ans + cnt[i] * pow(k, std::max(gcd, i * gcd - n - 1))) % mod;
			cnt[i] = 0;
		}
	}
	cout << ans * pow(k, mod - 2 - n) % mod << '\n';
}