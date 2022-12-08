#include <bits/stdc++.h>

using i64 = long long;

const int mod = 1e9 + 7;

std::vector<int> prime;
int vis[100005];
int phi[100005];

void euler_phi() {
	phi[1] = 1;
	for (int i = 2; i < 100005; ++i) {
		if (!vis[i])prime.push_back(i), phi[i] = i - 1;
		for (int j = 0; j < prime.size() && i * prime[j] < 100005; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}

std::vector<int> p[100005];

void init() {
	for (int i = 1; i < 100005; ++i) {
		for (int j = i + i; j < 100005; j += i) {
			p[j].push_back(i);
		}
	}
}

void solve() {
	int n;
	std::cin >> n;
	i64 ans = 0;
	for (int i = 1; i <= n - 2; ++i) {
		int x = n - i;
		for (int j: p[x]) {
			ans = (ans + std::lcm(1ll * i, std::gcd(x, j)) % mod * phi[x / j]) % mod;
		}
	}
	std::cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	euler_phi();
	init();
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}