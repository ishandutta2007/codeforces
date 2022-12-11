#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n; scanf("%d", &n);
	vector<int> L(n), R(n), C(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &L[i], &R[i], &C[i]);
	}
	map<pair<int, int>, ll> cheapest;
	int curL = -1, curR = -1, curLC = -1, curRC = -1;
	for (int i = 0; i < n; ++i) {
		// update cheapest
		pair<int, int> cint = make_pair(L[i], R[i]);
		if (cheapest.count(cint) == 0) {
			cheapest[cint] = C[i];
		} else {
			cheapest[cint] = min(cheapest[cint], (ll)C[i]);
		}
		// case 1: different segments
		if (i == 0) {
			curL = L[i], curR = R[i], curLC = curRC = C[i];
		} else {
			if (L[i] < curL || (L[i] == curL && C[i] < curLC)) {
				curL = L[i];
				curLC = C[i];
			}
			if (R[i] > curR || (R[i] == curR && C[i] < curRC)) {
				curR = R[i];
				curRC = C[i];
			}
		}
		ll ans = (ll)curLC + curRC;
		if (cheapest.count(make_pair(curL, curR)) > 0) {
			ans = min(ans, cheapest[make_pair(curL, curR)]);
		}
		printf("%lld\n", ans);
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}