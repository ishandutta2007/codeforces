#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	int s = 0, i;
	for (i = 0; s < n; ++i) {
		s += i;
	}
	if (s == n + 1)
		printf("%d\n", i);
	else
		printf("%d\n", i - 1);
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