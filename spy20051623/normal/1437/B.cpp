#include <bits/stdc++.h>

using namespace std;

char s[100005];

void solve() {
	int n;
	scanf("%d%s", &n, s);
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == s[i + 1]) ++ans;
	}
	printf("%d\n", (int) ceil(ans * 0.5));
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