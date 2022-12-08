#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b;
	scanf("%d%d", &a, &b);
	vector<int> v;
	int k = max((a + b) / 2 - min(a, b), 0);
	if ((a + b) % 2) {
		for (int i = k; i <= (a + b) / 2; ++i) {
			v.push_back(i);
			v.push_back(a + b - i);
		}
	} else {
		for (int i = k; i <= (a + b) / 2; i += 2) {
			v.push_back(i);
			if (i != (a + b) / 2) v.push_back(a + b - i);
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i : v) printf("%d ", i);
	putchar('\n');
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