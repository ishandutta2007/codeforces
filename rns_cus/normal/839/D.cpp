#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
#define N 1000010

vector <int> v[N];
int dp[N], n, a[N];

void init() {
	for (int i = 2; i < N; i ++) {
		for (int j = i; j < N; j += i) {
			v[j].push_back(i);
		}
	}
}

int powmod(int x, int k) {
	int ret = 1;
	for(; k; k >>= 1) {
		if (k & 1) ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod;
	} return ret;
}

int main() {
	///freopen("in.txt", "r", stdin);
	///freopen("myout.txt", "w", stdout);
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		for (auto y : v[a[i]]) {
			dp[y] ++;
		}
	}

	for (int i = 2; i <= 1000000; i ++) {
		if (dp[i]) {
			a[i] = 1ll * powmod(2, dp[i] - 1) % mod * dp[i] % mod;
			//cout << i << " " << a[i] << endl;
		}
	}

	ll ans = 0;
	for (int i = 1000000; i > 1; i --) {
		if (dp[i]) {
			///cout << i << " " << a[i] << endl;
			ans += 1ll * i * a[i] % mod;
			ans %= mod;
			for (auto y : v[i]) {
				a[y] = (mod + a[y] - a[i]) % mod;
			}
		}
	}

	cout << ans << endl;
}