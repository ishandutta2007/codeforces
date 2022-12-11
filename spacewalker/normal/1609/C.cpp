#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int AMAX = 1000010;

bool isPrime[AMAX];

ll solve() {
	int n, e; scanf("%d %d", &n, &e);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	vector<vector<int>> groups(e);
	for (int i = 0; i < n; ++i) {
		groups[i%e].push_back(arr[i]);
	}
	ll ans = 0;
	for (auto grp : groups) {
		int k = grp.size();
		vector<ll> oneBefore(k), oneAfter(k);
		for (int i = 1; i < k; ++i) {
			if (grp[i-1] != 1) oneBefore[i] = 0;
			else oneBefore[i] = 1 + oneBefore[i-1];
		}
		for (int i = k - 2; i >= 0; --i) {
			if (grp[i+1] != 1) oneAfter[i] = 0;
			else oneAfter[i] = 1 + oneAfter[i+1];
		}
		/*
		for (int v : oneBefore) printf("%d ", v);
		printf("\n");
		for (int v : oneAfter) printf("%d ", v);
		printf("\n");
		*/
		for (int i = 0; i < k; ++i) {
			// printf("%d prime %d %lld %lld\n", grp[i], isPrime[grp[i]], oneBefore[i], oneAfter[i]);
			if (isPrime[grp[i]]) ans += (oneBefore[i] + 1) * (oneAfter[i] + 1) - 1;
		}
	}
	return ans;
}

int main() {
	for (int i = 2; i < AMAX; ++i) isPrime[i] = true;
	for (int i = 2; i < AMAX; ++i) {
		if (!isPrime[i]) continue;
		for (int j = 2 * i; j < AMAX; j += i) isPrime[j] = false;
	}
	int t; scanf("%d", &t);
	while (t--) printf("%lld\n", solve());
}