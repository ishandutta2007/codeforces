#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int possibleForK(vector<int> &costs, int budget, int k) {
	vector<ll> newcosts(costs.size(), 0);
	for (ll i = 0; i < costs.size(); ++i) {
		newcosts[i] = costs[i] + (i + 1) * k;
	}
	sort(newcosts.begin(), newcosts.end());
	ll costToBuy = 0;
	for (int i = 0; i < k; ++i) {
		costToBuy += newcosts[i];
	}
	return (costToBuy <= budget ? costToBuy : -1);
}

int main() {
	int n, s; scanf("%d %d", &n, &s);
	vector<int> costs(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &costs[i]);
	}

	int lo = 0;
	int hi = n;
	// binary search for the lowest k where this is NOT possible
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		ll toBuyMid = possibleForK(costs, s, mid);
		if (toBuyMid == -1) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	ll toBuyFinal = possibleForK(costs, s, lo);
	if (toBuyFinal == -1) {
		int highestCount = lo - 1;
		ll minForHighest = possibleForK(costs, s, highestCount);
		printf("%d %lld", highestCount, minForHighest);
	} else {
		// there does not exist k such that this is possible
		ll buyAll = possibleForK(costs, s, n);
		printf("%d %lld", n, buyAll);
	}
	return 0;
}