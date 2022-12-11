#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll INF = 1000000000000000000;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> safeties(m);
	for (int i = 0; i < m; ++i) scanf("%d", &safeties[i]);
	int g, r; scanf("%d %d", &g, &r);
	sort(begin(safeties), end(safeties));
	vector<int> distToNext(m, -1), distToPrev(m, -1);
	for (int i = 1; i < m; ++i) distToNext[i-1] = safeties[i] - safeties[i-1];
	for (int i = 0; i + 1 < m; ++i) distToPrev[i+1] = safeties[i+1] - safeties[i];
	vector<vector<int>> timeToReach(m, vector<int>(g + 1, -1)); // THIS IS IN DAY CYCLES
	deque<pair<int, int>> q;
	q.emplace_back(0, 0);
	timeToReach[0][0] = 0;
	while (!q.empty()) {
		int sidx, cdt;
		tie(sidx, cdt) = q.front(); q.pop_front();
//		printf("%d reachable %d in %d days\n", sidx, cdt, timeToReach[sidx][cdt]);
		if (distToPrev[sidx] > -1) {
			int nidx = sidx - 1, ndt = cdt + distToPrev[sidx];
			if (ndt <= g && timeToReach[nidx][ndt] == -1) {
				timeToReach[nidx][ndt] = timeToReach[sidx][cdt];
				q.emplace_front(nidx, ndt);
			}
		}
		if (sidx < m - 1) {
			int nidx = sidx + 1, ndt = cdt + distToNext[sidx];
			if (ndt <= g && timeToReach[nidx][ndt] == -1) {
				timeToReach[nidx][ndt] = timeToReach[sidx][cdt];
				q.emplace_front(nidx, ndt);
			}
		}
		if (cdt == g) {
			if (timeToReach[sidx][0] == -1) {
				timeToReach[sidx][0] = timeToReach[sidx][cdt] + 1;
				q.emplace_back(sidx, 0);
			}
		}
	}
	ll ans = INF;
	for (int pTime = 0; pTime <= g; ++pTime) {
		if (timeToReach[m-1][pTime] != -1) {
			ans = min(ans, (ll)(g + r) * timeToReach[m-1][pTime] + pTime);
		}
	}
	if (ans == INF) printf("-1\n");
	else printf("%lld\n", ans);
	return 0;
}