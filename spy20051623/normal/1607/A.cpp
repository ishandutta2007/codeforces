#include <bits/stdc++.h>

using namespace std;

char s[100], a[100];
int m[100];

void solve() {
	scanf("%s%s", a, s);
	for (int i = 0; i < 26; ++i) {
		m[a[i] - 'a'] = i;
	}
	int ans = 0, n = strlen(s);
	for (int i = 1; i < n; ++i) {
		ans += abs(m[s[i] - 'a'] - m[s[i - 1] - 'a']);
	}
	printf("%d\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}