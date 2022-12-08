#include <bits/stdc++.h>

using namespace std;
char s[100005];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int res = 1e9;
	for (int i = 0; i < 26; ++i) {
		char c = 'a' + i;
		int l = 0, r = n - 1, ans = 0;
		bool ok = true;
		while (l < r) {
			while (s[l] == c && s[r] == c) ++l, --r;
			while (s[l] == c) ++l, ++ans;
			while (s[r] == c) --r, ++ans;
			if (l >= r) break;
			if (s[l] != s[r]) {
				ok = false;
				break;
			}
			++l, --r;
		}
		if (ok) res = min(res, ans);
	}
	printf("%d\n", res == 1e9 ? -1 : res);
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