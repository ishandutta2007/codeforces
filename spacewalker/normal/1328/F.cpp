#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll getForwardAns(vector<int> arr, int k) {
	map<int, int> eqCountIfTakenHere;
	map<int, ll> stepsNeeded;
	map<int, int> outsiders;
	int n = arr.size();
	vector<int> outsiderPerElem(n);
	vector<ll> forwardCC(n);
	for (ll i = 1; i < n; ++i) {
		forwardCC[i] = forwardCC[i - 1] + i * abs(arr[i] - arr[i - 1]);
	}
	for (int i = 0; i < n; ++i) {
		if (i > 0 && arr[i] != arr[i - 1]) outsiderPerElem[i] = i;
		else if (i > 0) outsiderPerElem[i] = outsiderPerElem[i - 1];
	}
	for (int i = 0; i < n; ++i) {
		eqCountIfTakenHere[arr[i]] = i + 1;
		stepsNeeded[arr[i]] = forwardCC[i];
		outsiders[arr[i]] = outsiderPerElem[i];
	}
	ll ans = 1e18;
	for (int x : arr) {
		if (eqCountIfTakenHere[x] < k) continue;
//		printf("elem %d eqc %d steps %lld out %d\n", x, eqCountIfTakenHere[x], stepsNeeded[x], outsiders[x]);
		int core = eqCountIfTakenHere[x] - outsiders[x];
		if (core >= k) {
			ans = 0;	
		} else {
			int needed = k - core;
			ans = min(ans, stepsNeeded[x] - outsiders[x] + needed);
		}
	}
	return ans;
}

int main() {
//	ll x = 27948723984;
//	printf("%lld\n", x + (ll)100000 * abs(1000000000 - 1));
	int n, k; scanf("%d %d", &n, &k);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	sort(begin(arr), end(arr));
	ll ans = 0;
	int medOutsiders = 0;
	for (int i = 0; i < n; ++i) {
		ans += abs(arr[i] - arr[n/2]);
		if (arr[i] != arr[n/2]) ++medOutsiders;
	}
//	printf("med outsiders %d\n", medOutsiders);
	if (n - medOutsiders < k) {
		int needed = k - (n - medOutsiders);
//		printf("%d need\n", needed);
		ans += (needed - medOutsiders);
	} else {
		ans = 0;
	}
//	printf("median ans %lld\n", ans);
	ans = min(ans, getForwardAns(arr, k));
	reverse(begin(arr), end(arr));
//	printf("beginning reverse search\n");
	ans = min(ans, getForwardAns(arr, k));
	printf("%lld\n", ans);
	return 0;
}