#include <bits/stdc++.h>

using i64 = long long;

struct node {
	int dp[2][2]{};
	node *p[2]{};

	~node() {
		delete p[0];
		delete p[1];
	}
} *root;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), dp(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	root = new node;
	for (int i = 0; i < n; ++i) {
		node *p = root;
		for (int j = 29; j >= 0; --j) {
			for (int k = 0; k < 2; ++k) {
				for (int l = 0; l < 2; ++l) {
					if ((l ^ i >> j & 1) < (a[i] >> j & 1 ^ k)) {
						dp[i] = std::max(dp[i], p->dp[k][l] + 1);
					}
				}
			}
			int x = (a[i] ^ i) >> j & 1;
			if (!p->p[x]) p->p[x] = new node;
			p = p->p[x];
		}
		p = root;
		for (int j = 29; j >= 0; --j) {
			p->dp[i >> j & 1][a[i] >> j & 1] = std::max(p->dp[i >> j & 1][a[i] >> j & 1], dp[i]);
			p = p->p[(a[i] ^ i) >> j & 1];
		}
	}
	std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}