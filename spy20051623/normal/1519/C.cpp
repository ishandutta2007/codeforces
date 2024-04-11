#include <bits/stdc++.h>

using namespace std;

int u[200005];

vector<int> a[200005];
vector<long long> s[200005];

set<int> l[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &u[i]);
	}
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		a[u[i]].push_back(p);
	}
	for (int i = 1; i <= n; ++i) {
		if (!a[i].empty()) {
			sort(a[i].begin(), a[i].end(), greater<int>());
			s[i].push_back(a[i][0]);
			for (int j = 1; j < a[i].size(); ++j) {
				s[i].push_back(s[i][j - 1] + a[i][j]);
			}
		}
		for (int j = 1; j <= a[i].size(); ++j) {
			l[j].insert(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		long long sum = 0;
		for (int j : l[i]) {
			int k = s[j].size() / i * i - 1;
			sum += s[j][k];
		}
		printf("%lld ", sum);
	}
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		a[i].clear();
		s[i].clear();
		l[i].clear();
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}