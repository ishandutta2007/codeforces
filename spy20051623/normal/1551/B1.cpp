#include <bits/stdc++.h>

using namespace std;

int a[50];
char s[1000];

void solve() {
	memset(a, 0, sizeof a);
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		++a[s[i] - 'a'];
	}
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < 26; ++i) {
		if (a[i] >= 2)++ans;
		else if (a[i])++cnt;
	}
	ans += cnt / 2;
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