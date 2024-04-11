#include <bits/stdc++.h>

using namespace std;

char s[1000];
char v[1000];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	memcpy(v, s, sizeof s);
	sort(v, v + n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += v[i] != s[i];
	}
	printf("%d\n", ans);
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