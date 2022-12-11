#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll modexp(ll b, ll e, ll m) {
	if (e == 0) return 1;
	else return (e & 1 ? b : 1) * modexp(b * b % m, e/2, m) % m;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	sort(begin(arr), end(arr));
	vector<int> byMod(m);
	vector<vector<ll>> pairCount(m, vector<ll>(m));
	for (int i = n - 1; i >= 0; --i) {
		int asim = arr[i] % m;
		for (int k = 0; k < m; ++k) {
			pairCount[asim][k] += byMod[k];
		}
		++byMod[asim];
	}
	ll ans = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			ans = (ans * modexp((i - j + m) % m, pairCount[j][i], m)) % m;
		}
	}
	printf("%lld\n", ans);
	return 0;
}