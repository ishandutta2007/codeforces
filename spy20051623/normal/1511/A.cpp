#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, s = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int j;
		scanf("%d", &j);
		if (j != 2)
			++s;
	}
	printf("%d\n", s);
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