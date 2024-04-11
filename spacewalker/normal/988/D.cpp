#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll>> pDiffSets;

vector<ll> cDiffSet;

bool isPowerOfTwo(ll x) {
	return (x & (x - 1)) == 0;
}

void findSets() {
	bool isMaximal = true;
	for (int i = 0; i < 40; ++i) {
		// printf("att %d with len %lu\n", i, cDiffSet.size());
		ll cAdd = 1LL << i;
		bool valid = true;
		for (ll x : cDiffSet) {
			if (!isPowerOfTwo(x + cAdd)) valid = false;
		}
		if (valid) {
			// printf("pushing\n");
			isMaximal = false;
			cDiffSet.push_back(cAdd + (cDiffSet.empty() ? 0 : cDiffSet.back()));
			findSets();
			cDiffSet.pop_back();
		}
	}
	if (isMaximal) {
		pDiffSets.emplace_back(cDiffSet.begin(), cDiffSet.end());
	}
}

int main() {
	findSets();
	// for (auto dl : pDiffSets) {
	// 	for (ll diff : dl) printf("%lld ", diff);
	// 	printf("\n");
	// }
	// printf("END SETS\n");
	set<ll> pts;
	int n; scanf("%d", &n);
	vector<ll> ptlist(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &ptlist[i]);
		pts.insert(ptlist[i]);
	}
	vector<ll> bAns;
	for (ll x : ptlist) {
		vector<ll> cAns{x};
		for (auto dl : pDiffSets) {
			for (ll diff : dl) {
				if (pts.count(x + diff) > 0) cAns.push_back(x + diff);
			}
			if (cAns.size() > bAns.size()) bAns = cAns;
			cAns.assign(1, x);
		}
	}
	printf("%lu\n", bAns.size());
	for (ll v : bAns) printf("%lld ", v);
	printf("\n");
	return 0;
}