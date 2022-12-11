#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; scanf("%d", &n);
	if (n == 1) {
		printf("-1\n");
		return;
	}
	for (int i = 0; i < n - 2; ++i) printf("6");
	printf("23\n");
	return;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}