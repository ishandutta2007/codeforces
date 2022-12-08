#include <bits/stdc++.h>

using namespace std;

vector<int> v[2], s;

void solve() {
	v[0].clear();
	v[1].clear();
	s.clear();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		v[i % 2].push_back(p);
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	for (int i = 0; i < n; ++i) {
		s.push_back(v[i % 2][i / 2]);
	}
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] > s[i + 1]) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
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