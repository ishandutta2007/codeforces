#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
int vis[100005];

void euler() {
	for (int i = 2; i < 100005; ++i) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < 100005; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)break;
		}
	}
}

void solve() {
	long long n;
	cin >> n;
	if (n & 1) {
		cout << "2\n";
		return;
	}
	long long nn = n, p = 2;
	while ((n & 1) == 0) n >>= 1, p <<= 1;
	if (n == 1) cout << "-1\n";
	else {
		if (p < 1e9 && p * (p + 1) / 2 <= nn) {
			cout << p << '\n';
			return;
		}
		for (int i: prime) {
			if (1ll * i * i > n) break;
			if (n % i == 0 && 1ll * i * (i + 1) / 2 <= nn) {
				cout << i << '\n';
				return;
			}
			while (n % i == 0) n /= i;
		}
		if (n > 1 && n * (n + 1) / 2 <= nn) cout << n << '\n';
		else cout << "-1\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	euler();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}