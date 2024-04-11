#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		sum += p;
	}
	if (sum == n) {
		printf("0\n");
	} else if (sum < n) {
		printf("1\n");
	} else {
		printf("%d\n", sum - n);
	}
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