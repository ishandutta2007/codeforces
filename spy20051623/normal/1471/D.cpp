#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
int vis[1000005];
int num[1000005];

void euler() {
	for (int i = 2; i < 1000005; ++i) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < 1000005; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)break;
		}
	}
}

void init() {
	for (int i = 1; i < 1000005; ++i) {
		int x = i, y = 1;
		for (int j = 0; j < prime.size() && prime[j] * prime[j] <= x; ++j) {
			int cnt = 0;
			while (x % prime[j] == 0) {
				++cnt;
				x /= prime[j];
			}
			if (cnt & 1) y *= prime[j];
		}
		if (x > 1) y *= x;
		num[i] = y;
	}
}

unordered_map<int, int> m;

void solve() {
	m.clear();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		++m[num[p]];
	}
	int x = 0, y = 0, z = 0;
	for (auto &it: m) {
		x = max(x, it.second);
		if (it.second & 1 && it.first != 1) y = max(y, it.second);
		else z += it.second;
	}
	y = max(y, z);
	int q;
	scanf("%d", &q);
	while (q--) {
		long long p;
		scanf("%lld", &p);
		printf("%d\n", p ? y : x);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	euler();
	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}