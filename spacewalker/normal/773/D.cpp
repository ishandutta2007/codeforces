#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 2010;
constexpr ll INF = 1000000000000000000;

ll daan[NMAX][NMAX];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			scanf("%lld", &daan[i][j]);
		}
	}
	ll minEdgeWeight = INF;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) minEdgeWeight = min(minEdgeWeight, daan[i][j]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) daan[i][j] -= minEdgeWeight;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) daan[i][j] = daan[j][i];
	}
	vector<ll> cheapestNext(n, INF);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			cheapestNext[i] = min(cheapestNext[i], 2 * daan[i][j]);
//			printf("%d %d adj %lld\n", i, j, daan[i][j]);
		}
	}
	vector<ll> cDist = cheapestNext;
	set<pair<ll, int>> toVisit;
	for (int i = 0; i < n; ++i) toVisit.emplace(cDist[i], i);
	while (!toVisit.empty()) {
		ll dtc; int cur; tie(dtc, cur) = *toVisit.begin();
//		printf("vis %d yeet %lld\n", cur, dtc);
		toVisit.erase({dtc, cur});
		for (int nxt = 0; nxt < n; ++nxt) {
			if (nxt == cur) continue;
			ll wtn = dtc + daan[cur][nxt];
			if (wtn < cDist[nxt]) {
//				printf("push %d %lld\n", nxt, wtn);
				toVisit.erase({cDist[nxt], nxt});
				toVisit.emplace(cDist[nxt] = wtn, nxt);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%lld\n", cDist[i] + (n - 1) * minEdgeWeight);
	}
	return 0;
}