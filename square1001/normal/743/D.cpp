#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, p, q; long long a[200009], dp[200009]; vector<int> G[200009];
void rec(int pos, int pre) {
	dp[pos] = -1LL << 60;
	for (int i : G[pos]) {
		if (i == pre) continue;
		rec(i, pos);
		a[pos] += a[i];
		dp[pos] = max(dp[pos], dp[i]);
	}
	dp[pos] = max(dp[pos], a[pos]);
}
long long solve(int pos, int pre) {
	long long ret = -1LL << 60;
	vector<long long> v;
	for (int i : G[pos]) {
		if (i == pre) continue;
		long long res = solve(i, pos);
		ret = max(ret, res);
		v.push_back(dp[i]);
	}
	sort(v.begin(), v.end(), greater<long long>());
	if (v.size() <= 1) return ret;
	ret = max(ret, v[0] + v[1]);
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &p, &q); p--, q--;
		G[p].push_back(q);
		G[q].push_back(p);
	}
	rec(0, -1);
	long long ret = solve(0, -1);
	if (ret == -1LL << 60) puts("Impossible");
	else printf("%lld\n", ret);
	return 0;
}