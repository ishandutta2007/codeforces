#include <bits/stdc++.h>

using namespace std;

char s[200005];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	vector<int> v;
	for (int i = 1, cnt = 1; i <= n; ++i) {
		if (s[i] == s[i - 1]) ++cnt;
		else v.push_back(cnt), cnt = 1;
	}
	int ans = 0;
	for (int l = 0, r = 0; l < v.size();) {
		while (r < l) ++r;
		while (r < v.size() && v[r] == 1) ++r;
		if (r < v.size()) --v[r], ++l;
		else l += 2;
		++ans;
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