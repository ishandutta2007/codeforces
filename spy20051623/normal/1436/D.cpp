#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long num[N], ex[N], sum[N], cnt[N];
vector<int> g[N];

void dfs(int p) {
	if (g[p].empty()) cnt[p] = 1;
	sum[p] = num[p];
	for (int i : g[p]) dfs(i), cnt[p] += cnt[i], sum[p] += sum[i], ex[p] = max(ex[p], ex[i]);
	ex[p] = max(ex[p], (long long) ceil(1.0 * sum[p] / cnt[p]));
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		int from;
		scanf("%d", &from);
		g[from].push_back(i);
	}
	for (int i = 1; i <= n; ++i) scanf("%lld", &num[i]);
	dfs(1);
	printf("%lld\n", ex[1]);
	return 0;
}