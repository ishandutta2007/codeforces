#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; scanf("%d", &n);
	vector<int> returned(n);
	auto query = [&] (int i) {
		assert(0 <= i && i < n);
		printf("? %d\n", i + 1);
		fflush(stdout);
		int qi; scanf("%d", &qi);
		if (qi == 0) exit(0);
		else {
			++returned[qi - 1];
			return qi - 1;
		}
	};
	vector<int> ans(n, -1);
	for (int i = 0; i < n; ++i) {
		if (ans[i] != -1) continue;
		int cur = query(i);
		while (returned[cur] < 2) {
			int nxt = query(i);
			ans[cur] = nxt;
			cur = nxt;
		}
	}
	printf("!");
	for (int i = 0; i < n; ++i) {
		printf(" %d", ans[i] + 1);	
	}
	printf("\n");
	fflush(stdout);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}