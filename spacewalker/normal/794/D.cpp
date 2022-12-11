#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

ll countEdges(vector<int> ans) {
	map<int, ll> idxCount;
	for (int label : ans) {
		++idxCount[label];
	}
	vector<pair<int, ll>> countList(idxCount.begin(), idxCount.end());
	ll ret = 0;
	for (auto ct : countList) {
		ret += (ct.second) * (ct.second - 1) / 2;
	}
	for (int i = 0; i < (int)countList.size() - 1; ++i) {
		ret += (countList[i].second) * (countList[i+1].second);
	}
	return ret;
}

bool verifyAnswer(const vector<vector<int>> &graph, int m, vector<int> ans) {
	if (m != countEdges(ans)) {
		return false;
	}
	for (int i = 0; i < graph.size(); ++i) {
		for (int j : graph[i]) {
			if ((ans[i] - ans[j]) < -1 || (ans[i] - ans[j]) > 1) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		graph[--x].push_back(--y);
		graph[y].push_back(x);
	}
	for (int i = 0; i < n; ++i) {
		graph[i].push_back(i);
		sort(graph[i].begin(), graph[i].end());
	}
	queue<pair<int, pair<int, int>>> q;
	vector<int> ans(n, -1);
	q.emplace(0, make_pair(2, 500000));
	bool failedDeduction = false;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur.first < 0) {
			continue;
		}
		vector<int> matesOfCur;
		vector<int> otherGroups;
		for (int neigh : graph[cur.first]) {
			if (ans[neigh] == -1 && graph[neigh] == graph[cur.first]) {
				matesOfCur.push_back(neigh);
			} else {
				otherGroups.push_back(neigh);
			}
		}
		ans[cur.first] = cur.second.second;
		for (int i : matesOfCur) {
			ans[i] = cur.second.second;
		}
		// now i need to pass the torch to the next groups
		if (cur.second.first != 2) {
			// take all the unvisited neighbors; put them in one group
			int nextToVisit = -1;
			for (int neigh : graph[cur.first]) {
				if (ans[neigh] == -1) {
					nextToVisit = neigh;
					break;
				}
			}
			q.emplace(nextToVisit, make_pair(cur.second.first, cur.second.second + (cur.second.first == 0 ? -1 : 1)));
		} else {
			vector<int> firstSet;
			int firstRep = -1;
			vector<int> secondSet;
			int secondRep = -1;
			for (int toSort : otherGroups) {
				if (firstSet.empty()) {
					firstSet = graph[toSort];
					firstRep = toSort;
				} else if (graph[toSort] != firstSet) {
					if (secondSet.empty()) {
						secondSet = graph[toSort];
						secondRep = toSort;
					} else if (graph[toSort] != secondSet) {
						failedDeduction = true;
					}
				}
			}
			if (failedDeduction) {
				break;
			} else {
				if (firstRep != -1) {
					q.emplace(firstRep, make_pair(0, 500000 - 1));
				}
				if (secondRep != -1) {
					q.emplace(secondRep, make_pair(1, 500000 + 1));
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] == -1) {
			failedDeduction = true;
		}
	}
	if (failedDeduction || !verifyAnswer(graph, m, ans)) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i) {
			cout << (i == 0 ? "" : " ") << ans[i];
		}
		cout << endl;
	}
	return 0;
}