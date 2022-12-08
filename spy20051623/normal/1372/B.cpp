#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
int vis[33333];

void euler() {
	for (int i = 2; i < 33333; ++i) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < 33333; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)break;
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i: prime) {
		if (i * i > n) break;
		if (n % i == 0) {
			cout << n / i << ' ' << n - n / i << '\n';
			return;
		}
	}
	cout << 1 << ' ' << n - 1 << '\n';
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