#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pll;

priority_queue <pll> q;

pll a[100010];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%I64d%I64d", &a[i].fi, &a[i].se);
	long long sum = 0;
	for (int i = 0; i < n; i++) sum += a[i].fi, q.push(mp(a[i].se, a[i].fi));
	long long tot = 0, ans = sum;
	while (q.size()) {
		while (q.size() && q.top().fi >= sum) q.pop();
		if (!q.size()) break;
		pll t = q.top(); q.pop();
		long long tmp = min(sum - t.fi, t.se);
		tot += tmp, sum -= tmp;
	}
	printf("%I64d\n", ans + ans - tot);
	return 0;
}