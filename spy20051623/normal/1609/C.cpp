#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N];

vector<int> prime;
int vis[1000005];

void euler() {
	vis[1] = 1;
	for (int i = 2; i < 1000005; ++i) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < 1000005; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)break;
		}
	}
}

void solve() {
	int n, e;
	scanf("%d%d", &n, &e);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	long long ans = 0;
	for (int i = 1; i <= e; ++i) {
		vector<int> v;
		for (int j = i; j <= n; j += e) {
			v.push_back(a[j]);
		}
		for (int j = 0; j < v.size(); ++j) {
			if (vis[v[j]]) continue;
			int l = j, r = j;
			while (l > 0 && v[l - 1] == 1) --l;
			while (r < (int) v.size() - 1 && v[r + 1] == 1) ++r;
			ans += 1ll * (j - l + 1) * (r - j + 1) - 1;
		}
	}
	printf("%lld\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	euler();
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}