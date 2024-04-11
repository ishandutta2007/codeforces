#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	set<pair<int, int>> elist;
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int x, y; cin >> x >> y;
		elist.emplace(--x, --y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	vector<int> startPoints;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			startPoints.push_back(i);
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				for (int neigh : graph[cur]) {
					if (!visited[neigh]) {
						elist.erase(make_pair(cur, neigh));
						elist.erase(make_pair(neigh, cur));
						visited[neigh] = true;
						q.push(neigh);
					}
				}
			}
		}
	}
	vector<pair<int, int>> uselessEdges(elist.begin(), elist.end());
	cout << uselessEdges.size() << endl;
	for (int i = 0; i < (int)uselessEdges.size(); ++i) {
		cout << uselessEdges[i].first + 1 << " " << uselessEdges[i].second + 1 <<  // oof
			" " << startPoints[i] + 1<< " " << startPoints[i + 1] + 1 << endl;
	}
	return 0;
}