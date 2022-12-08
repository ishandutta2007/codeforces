#include <bits/stdc++.h>

using namespace std;

set<int> s[105][105];

void solve() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if (s[n][m].find(k) != s[n][m].end())
		printf("YES\n");
	else
		printf("NO\n");
}

void init() {
	s[1][1].insert(0);
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			for (int k : s[i][j]) {
				s[i + 1][j].insert(k + j);
				s[i][j + 1].insert(k + i);
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}