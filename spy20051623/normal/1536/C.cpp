#include <bits/stdc++.h>

using namespace std;

char s[500005];
int d[500005];
int k[500005];
map<pair<int, int>, int> mp;

void solve() {
	mp.clear();
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'D') {
			d[i] = d[i - 1] + 1;
			k[i] = k[i - 1];
		} else {
			d[i] = d[i - 1];
			k[i] = k[i - 1] + 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		int dd = d[i];
		int kk = k[i];
		if (!dd || !kk) {
			printf("%d ", i);
			continue;
		}
		int g = __gcd(dd, kk);
		dd /= g;
		kk /= g;
		printf("%d ", ++mp[make_pair(dd, kk)]);
	}
	printf("\n");
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