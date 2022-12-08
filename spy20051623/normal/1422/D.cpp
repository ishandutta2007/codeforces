#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 5;
int vis[N], x[N], y[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%d%d%d%d", &x[0], &y[0], &x[m + 1], &y[m + 1]);
	vis[0] = vis[m + 1] = -1;
	vector<pii> xx, yy;
	xx.emplace_back(x[0], 0);
	yy.emplace_back(y[0], 0);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		vis[i] = -1;
		xx.emplace_back(x[i], i);
		yy.emplace_back(y[i], i);
	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.emplace(0, 0);
	while (!q.empty()) {
		pii p = q.top();
		q.pop();
		if (vis[p.second] > -1) continue;
		vis[p.second] = p.first;
		int nx = lower_bound(xx.begin(), xx.end(), pii{x[p.second], p.second}) - xx.begin();
		int ny = lower_bound(yy.begin(), yy.end(), pii{y[p.second], p.second}) - yy.begin();
		if (nx > 0) {
			int dis = vis[p.second] + min(abs(x[p.second] - x[xx[nx - 1].second]),
										  abs(y[p.second] - y[xx[nx - 1].second]));
			q.emplace(dis, xx[nx - 1].second);
		}
		if (nx < m) {
			int dis = vis[p.second] + min(abs(x[p.second] - x[xx[nx + 1].second]),
										  abs(y[p.second] - y[xx[nx + 1].second]));
			q.emplace(dis, xx[nx + 1].second);
		}
		if (ny > 0) {
			int dis = vis[p.second] + min(abs(x[p.second] - x[yy[ny - 1].second]),
										  abs(y[p.second] - y[yy[ny - 1].second]));
			q.emplace(dis, yy[ny - 1].second);
		}
		if (ny < m) {
			int dis = vis[p.second] + min(abs(x[p.second] - x[yy[ny + 1].second]),
										  abs(y[p.second] - y[yy[ny + 1].second]));
			q.emplace(dis, yy[ny + 1].second);
		}
	}
	int ans = 2e9 + 10;
	for (int i = 0; i <= m; ++i) {
		ans = min(ans, abs(x[m + 1] - x[i]) + abs(y[m + 1] - y[i]) + vis[i]);
	}
	printf("%d\n", ans);
	return 0;
}