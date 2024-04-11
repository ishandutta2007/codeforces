#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9L + 7;
const ll inv2 = (mod + 1) / 2;
const ll inv3 = (mod + 1) / 3;
const ll inv6 = (mod + 1) / 6;

ll cn2(ll n) {
	return n * (n - 1) % mod * inv2 % mod;
}
ll cn3(ll n) {
	return n * (n - 1) % mod * (n - 2) * inv6 % mod;
}

const int N = 4e3L + 11;
int gcd[N][N];

int main() {
	for(int k = 1; k < N; k ++)
		for(int i = 0; i < N; i += k)
			for(int j = 0; j < N; j += k)
				gcd[i][j] = k;

	ios :: sync_with_stdio(0);
	int n, m; cin >> n >> m;

	ll ans = 0;
	for(int i = 0; i < 2; i ++)
		for(int j = 0; j < 2; j ++) {
			ll c[4];
			for(int s = 0; s < 2; s ++)
				for(int t = 0; t < 2; t ++) {
					ll a = (((i ^ s) & 1) ? (n + 1) / 2 : n / 2 + 1);
					ll b = (((j ^ t) & 1) ? (m + 1) / 2 : m / 2 + 1);
					c[s * 2 + t] = a * b;
				}
			c[0] --;

			ll tmp = 0;
			for(int s = 0; s < 4; s ++)
				for(int t = s; t < 4; t ++) {
					int x = (s >> 1) * (t & 1) + (s & 1) * (t >> 1);
					if(x % 2 == 0) {
						if(s == t)
							tmp += cn2(c[s]);
						else
							tmp += c[s] * c[t];
						tmp %= mod;
					}
				}

			ll a = ((i & 1) ? (n + 1) / 2 : n / 2 + 1);
			ll b = ((j & 1) ? (m + 1) / 2 : m / 2 + 1);
			ans += tmp * a * b;
			ans %= mod;
		}
	ans = ans * inv3 % mod;

	for(int i = 0; i <= n; i ++)
		for(int j = 0; j <= m; j ++) if((i > 0 || j > 0) && /*__gcd(i, j) == 1*/ gcd[i][j] == 1) {
			for(int k = 0; k * i <= n && k * j <= m; k ++) {
				ll t = ll(n - k * i + 1) * (m - k * j + 1);
				if((k + 1) * i <= n && (k + 1) * j <= m)
					t -= ll(n - (k + 1) * i + 1) * (m - (k + 1) * j + 1);
				ans -= t * cn2(k);
				if(i > 0 && j > 0)
					ans -= t * cn2(k);
				ans %= mod;
			}
		}
	cout << (ans * 6 % mod + mod) % mod << '\n';

	return 0;
}