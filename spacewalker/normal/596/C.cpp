#include <bits/stdc++.h>

using namespace std;
constexpr int OFFSET = 100050;

vector<int> pointByIndex[2 * OFFSET];

int dx[] = {1, 0};
int dy[] = {0, 1};

int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> pts(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &pts[i].first, &pts[i].second);
		pointByIndex[pts[i].second - pts[i].first + OFFSET].push_back(i);
	}
	for (int i = 0; i < 2 * OFFSET; ++i) {
		sort(begin(pointByIndex[i]), end(pointByIndex[i]), [&pts] (int i, int j) {
				return pts[i] > pts[j];
		});
	}
	vector<int> ans(n, -1);
	for (int i = 0; i < n; ++i) {
		int w; scanf("%d", &w);
		if (pointByIndex[w + OFFSET].empty()) break;
		ans[i] = pointByIndex[w + OFFSET].back();
		pointByIndex[w + OFFSET].pop_back();
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] == -1) {
			printf("NO\n");
			return 0;
		}
	}
	map<pair<int, int>, int> ptIndex;
	for (int i = 0; i < n; ++i) {
		ptIndex[pts[i]] = i;
	}
	vector<int> pointLabel(n);
	for (int i = 0; i < n; ++i) pointLabel[ans[i]] = i;
	for (int i = 0; i < n; ++i) {
		for (int mt = 0; mt < 2; ++mt) {
			int nx = pts[i].first + dx[mt], ny = pts[i].second + dy[mt];
			pair<int, int> neighPoint = make_pair(nx, ny);
			if (ptIndex.count(neighPoint) > 0) {
				if (pointLabel[ptIndex[neighPoint]] < pointLabel[i]) {
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; ++i) printf("%d %d\n", pts[ans[i]].first, pts[ans[i]].second);
	return 0;
}