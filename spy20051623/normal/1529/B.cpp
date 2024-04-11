#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	int p = 0, q = 0, s = 0x3f3f3f3f;
	vector<int> m;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (a <= 0) {
			++p;
			m.push_back(a);
		} else {
			++q;
			s = min(s, a);
		}
	}
	sort(m.begin(), m.end());
	int e;
	if (!q)
		e = 0;
	else if (m.size() <= 1)
		e = 1;
	else {
		int k = 0x3f3f3f3f;
		for (int i = 0; i < m.size() - 1; ++i) {
			k = min(k, m[i + 1] - m[i]);
		}
		if (k < s)
			e = 0;
		else
			e = 1;
	}
	printf("%d\n", p + e);
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