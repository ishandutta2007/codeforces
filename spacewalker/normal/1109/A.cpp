#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 1000000;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1000000000000000000;

int main() {
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	map<int, int> oddIndexPref;
	map<int, int> evenIndexPref;
	vector<int> pref(n + 1);
	for (int i = 0; i < n; ++i) {
		pref[i+1] = pref[i] ^ arr[i];
		// printf("P%d\n", pref[i+1]);
	}
	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		if (i % 2 == 0) {
			ans += evenIndexPref[pref[i]];
			evenIndexPref[pref[i]]++;
		} else {
			ans += oddIndexPref[pref[i]];
			oddIndexPref[pref[i]]++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}