#include <bits/stdc++.h>

using namespace std;

int s[200005];

void solve() {
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	memset(s, 0, sizeof s);
	int c;
	for (int i = 0; i < l; ++i) {
		scanf("%d", &c);
		++s[c];
	}
	for (int i = 0; i < r; ++i) {
		scanf("%d", &c);
		--s[c];
	}
	int k = abs(l - r) / 2;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += abs(s[i]);
		if (l > r) {
			if (s[i] > 0)
				k -= abs(s[i]) / 2;
		} else if (l < r) {
			if (s[i] < 0)
				k -= abs(s[i]) / 2;
		}
	}
	k = max(k, 0);
	printf("%d\n", sum / 2 + k);
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