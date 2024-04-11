#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n; ll h; scanf("%d %lld", &n, &h);
	vector<pair<ll, ll>> flows(n);
	for (int i = 0; i < n; ++i) scanf("%lld %lld", &flows[i].first, &flows[i].second);
	vector<ll> gaps(n);
	vector<ll> ranges(n);
	for (int i = 0; i < n - 1; ++i) {
		gaps[i] = flows[i+1].first - flows[i].second;
		// printf("gap %d = %lld\n", i, gaps[i]);
	}
	gaps[n-1] = 1000000000;
	for (int i = 0; i < n; ++i) ranges[i] = flows[i].second - flows[i].first;
	ll ans = h + ranges[n-1];
	ll gapDrop = n - 1, cGapSum = gaps[n-1], cRangeSum = ranges[n-1];
	// printf("start %lld %lld %lld\n", gapDrop, cGapSum, cRangeSum);
	for (int i = n - 2; i >= 0; --i) {
		// find the min k such that sum of gaps from i to k is >= h
		cGapSum += gaps[i];
		cRangeSum += ranges[i];
		// printf("at %d height %lld\n", i, h);
		while (gapDrop > i && cGapSum - gaps[gapDrop] >= h) {
			// printf("at i %d moving gd %lld\n", i, gapDrop);
			// printf("cgs %lld cd %lld\n", cGapSum, gaps[gapDrop]);
			cGapSum -= gaps[gapDrop];
			cRangeSum -= ranges[gapDrop];
			--gapDrop;
		}
		ans = max(ans, cRangeSum + h);
	}
	printf("%lld\n", ans);
	return 0;
}