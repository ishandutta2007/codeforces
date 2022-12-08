#include <bits/stdc++.h>

using namespace std;

char s[1000005];
int a[2][1000005];

void solve() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '[' || s[i] == ']') a[i & 1][i] = a[i & 1][i - 1] + 1;
		else a[i & 1][i] = a[i & 1][i - 1];
		a[i & 1 ^ 1][i] = a[i & 1 ^ 1][i - 1];
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", abs((a[0][r] - a[0][l - 1]) - (a[1][r] - a[1][l - 1])));
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