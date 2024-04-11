#include <bits/stdc++.h>

using namespace std;
const int N = 2e7 + 5;
int a[N];
long long dp[N];

vector<int> prime;
int vis[N];

void euler() {
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < N; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)break;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	euler();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		++a[p];
	}
	for (int i: prime) {
		for (int j = (N - 1) / i; j >= 1; --j) {
			a[j] += a[i * j];
		}
	}
	for (int i = N - 1; i > 0; --i) {
		dp[i] = 1ll * i * a[i];
		for (int j: prime) {
			if (1ll * i * j >= N) break;
			dp[i] = max(dp[i], dp[i * j] + 1ll * i * (a[i] - a[i * j]));
		}
	}
	printf("%lld\n", dp[1]);
	return 0;
}