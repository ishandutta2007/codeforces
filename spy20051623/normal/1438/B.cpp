#include <bits/stdc++.h>

using namespace std;

set<int> s;

void solve() {
	int n;
	scanf("%d", &n);
	s.clear();
	bool ok = false;
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		if (s.find(p) != s.end()) {
			ok = true;
		}
		s.insert(p);
	}
	if (ok)printf("YES\n");
	else printf("NO\n");
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