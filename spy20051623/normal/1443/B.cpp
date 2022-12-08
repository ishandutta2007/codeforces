#include <bits/stdc++.h>

using namespace std;

char s[100005];

void solve() {
	int a, b;
	scanf("%d%d", &a, &b);
	scanf("%s", s + 1);
	int n = strlen(s + 1), pos = 1, cnt = 0;
	while (pos <= n && s[pos] == '0') ++pos;
	if (pos == n + 1) {
		puts("0");
		return;
	}
	long long ans = a;
	for (int i = pos + 1; i <= n; ++i) {
		if (s[i] == '1') {
			if (s[i - 1] == '0') {
				ans += min(1ll * a, 1ll * b * cnt);
				cnt = 0;
			}
		} else {
			++cnt;
		}
	}
	printf("%lld\n", ans);
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