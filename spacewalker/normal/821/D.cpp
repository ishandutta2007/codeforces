#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <unordered_map>
#define DECODE_BASE 5000
#define INF 1000000000

using namespace std;

int n, m, k; 

int encodePair(int x, int y) {
	return DECODE_BASE*x + y;
}

pair<int, int> decodePair(int ep) {
	return make_pair(ep/DECODE_BASE, ep%DECODE_BASE);
}

int dx[4]= {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int main() {
	scanf("%d %d %d", &n, &m, &k);
	vector<vector<pair<int, int>>> graph(k + n + m, vector<pair<int, int>>());
	// id 0 to k-1 is for point-to-point
	// k to k + n - 1 is for dummy row vertices
	// k + n to k + n + m - 1 is for dummy col vertices
	unordered_map<int, int> indices;
	vector<pair<int, int>> points;
	int startPoint = -1;
	for (int i = 0; i < k; ++i) {
		int r, c; scanf("%d %d", &r, &c);
		if (r == 1 && c == 1) {
			startPoint = i;
		}
		points.emplace_back(--r, --c);
		indices[encodePair(r, c)] = i;
		for (int offX = -1; offX <= 1; ++offX) {
			if (offX + r >= 0 && offX + r < n) {
				graph[i].emplace_back(k + r + offX, 1);
				graph[k + r + offX].emplace_back(i, 0);
				//printf("%d and %d adjacent\n", i, k + r + offX);
			}
		}
		for (int offY = -1; offY <= 1; ++offY) {
			if (offY + c >= 0 && offY + c < m) {
				graph[i].emplace_back(k + n + c + offY, 1);
				graph[k + n + c + offY].emplace_back(i, 0);
				//printf("%d and %d adjacent\n", i, k + n + c + offY);
			}
		}
	}
	for (int i = 0; i < k; ++i) {
		auto pt = points[i];
		for (int mt = 0; mt < 4; ++mt) {
			int nx = pt.first + dx[mt];
			int ny = pt.second + dy[mt];
			if (indices.find(encodePair(nx, ny)) != indices.end()) {
				int pidx = indices[encodePair(nx, ny)];
				graph[i].emplace_back(pidx, 0);
				graph[pidx].emplace_back(i, 0);
			}
		}
	}
	deque<int> dq;
	vector<int> dist(n + m + k, -1);
	dq.push_back(startPoint);
	dist[startPoint] = 0;
	while (!dq.empty()) {
		int cur = dq.front(); dq.pop_front();
		for (auto neigh_d : graph[cur]) {
			if (dist[neigh_d.first] == -1) {
				dist[neigh_d.first] = dist[cur] + neigh_d.second;
				if (neigh_d.second == 0) {
					dq.push_front(neigh_d.first);
				} else {
					dq.push_back(neigh_d.first);
				}
			}
		}
	}
	if (indices.find(encodePair(n-1, m-1)) != indices.end()) {
		printf("%d\n", dist[indices[encodePair(n-1, m-1)]]);
	} else {
		int ans = INF;
		for (auto pt : points) {
			if ((pt.first >= n - 2 || pt.second >= m - 2) && dist[indices[encodePair(pt.first, pt.second)]] >= 0) {
				//printf("point %d %d is valid prec\n", pt.first, pt.second);
				ans = min(ans, dist[indices[encodePair(pt.first, pt.second)]] + 1);
			}
		}
		printf("%d\n", (ans == INF ? - 1 : ans));
	}
	return 0;
}