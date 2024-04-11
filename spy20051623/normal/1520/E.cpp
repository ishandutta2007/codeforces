#include <bits/stdc++.h>

using namespace std;

char s[1000005];

void solve() {
	int n;
	scanf("%d", &n);
	getchar();
	gets(s);
	vector<int> pos;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*')
			pos.push_back(i);
	}
	if (pos.empty()) {
		printf("0\n");
		return;
	}
	int m = pos[pos.size() / 2];
	int mx = pos.size() / 2;
	long long ans = 0;
	for (int i = 0; i < pos.size(); ++i) {
		ans += abs(pos[i] - m) - abs(i - mx);
	}
	printf("%lld\n", ans);
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