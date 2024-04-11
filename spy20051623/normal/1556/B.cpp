#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	vector<int> v[2];
	for (int i = 1; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		v[p & 1].push_back(i);
	}
	if (abs((int) v[0].size() - (int) v[1].size()) > 1) {
		printf("-1\n");
		return;
	}
	int sum = 0;
	if (n & 1) {
		if (v[0].size() > v[1].size()) {
			for (int i = 1; i + i - 1 <= n; ++i) {
				sum += abs(v[0][i - 1] - (i + i - 1));
			}
		} else {
			for (int i = 1; i + i - 1 <= n; ++i) {
				sum += abs(v[1][i - 1] - (i + i - 1));
			}
		}
	} else {
		int s1 = 0, s2 = 0;
		for (int i = 1; i + i - 1 <= n; ++i) {
			s1 += abs(v[0][i - 1] - (i + i - 1));
		}
		for (int i = 1; i + i <= n; ++i) {
			s2 += abs(v[0][i - 1] - (i + i));
		}
		sum = min(s1, s2);
	}
	printf("%d\n", sum);
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