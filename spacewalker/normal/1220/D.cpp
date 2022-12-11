#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll pfac2(ll x) {
	if (x % 2 == 1) return 0;
	else return pfac2(x / 2) + 1;
}

vector<ll> byfac[100];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		ll b; scanf("%lld", &b);
		byfac[pfac2(b)].push_back(b);
	}
	int ans = 0;
	for (int i = 0; i < 100; ++i) {
		ans = max(ans, (int)byfac[i].size());
	}
	int groupToKeep = 0;
	for (int i = 0; i < 100; ++i) {
		if (byfac[i].size() == ans) groupToKeep = i;
	}
	vector<ll> toRem;
	for (int i = 0; i < 100; ++i) {
		if (groupToKeep == i) continue;
		for (ll x : byfac[i]) toRem.push_back(x);
	}
	printf("%lu\n", toRem.size());
	for (ll x : toRem) printf("%lld ", x);
	printf("\n");
	return 0;
}