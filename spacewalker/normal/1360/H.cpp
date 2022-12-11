#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int LEN_MAX = 61;

char bstr[LEN_MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; ll m; scanf("%d %lld", &n, &m);
		vector<ll> excluded;
		for (int i = 0; i < n; ++i) {
			scanf("%s", bstr);
			excluded.push_back(0);
			for (int i = 0; i < m; ++i) if (bstr[m - 1 - i] == '1') excluded.back() |= (1LL << i);
		}	
		set<int> excSet(begin(excluded), end(excluded));
		sort(begin(excluded), end(excluded));
		ll k = (1LL << m) - n;
		ll hinahanap = (k - 1) / 2;
		// find the first i such that [hinahanap] elements in the set are less than it
		ll lo = 0, hi = (1LL << m) - 1;
		while (lo < hi) {
			ll mid = lo + (hi - lo) / 2;
			ll lessSetCount = mid;
			for (ll x : excluded) if (x < mid) --lessSetCount;
			if (lessSetCount >= hinahanap) hi = mid;
			else lo = mid + 1;
		}
		while (excSet.count(lo) > 0) ++lo;
		for (int bit = m - 1; bit >= 0; --bit) {
			if ((1LL << bit) & lo) printf("1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}