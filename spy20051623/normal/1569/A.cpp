#include <bits/stdc++.h>

using namespace std;

char s[100];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] != s[i + 1]) {
			printf("%d %d\n", i + 1, i + 2);
			return;
		}
	}
	printf("-1 -1\n");
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