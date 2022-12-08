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
	const string s1 = "Ashishgup\n", s2 = "FastestFinger\n";
	int n;
	cin >> n;
	if (n == 1) {
		cout << s2;
		return;
	}
	if (n & 1) {
		cout << s1;
		return;
	}
	if (n == 2) {
		cout << s1;
		return;
	}
	int cnt = 0;
	while ((n & 1) == 0) {
		++cnt;
		n >>= 1;
	}
	if (n == 1) {
		cout << s2;
		return;
	}
	if (cnt > 1) {
		cout << s1;
		return;
	}
	int x = 0;
	for (int i: prime) {
		if (1ll * i * i > n) break;
		while (n % i == 0) {
			++x;
			n /= i;
		}
	}
	if (n) ++x;
	if (x == 1) cout << s2;
	else cout << s1;
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