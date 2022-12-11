#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

class SparseTable {
	int n;
	vector<vector<int>> table;
	vector<int> arr;
public:
	SparseTable() {}
	SparseTable(vector<int> orig) : n(orig.size()), table(log2(orig.size()) + 1, orig), arr(orig) {
		for (int i = 0; i < n; ++i) {
			table[0][i] = i;
		}
		for (int layer = 1; (1 << layer) <= n; ++layer) {
			for (int i = 0; (i + (1 << layer)) <= n; ++i) {
				int itc1 = table[layer-1][i];
				int itc2 = table[layer-1][i+(1 << (layer-1))];
				table[layer][i] = (arr[itc1] < arr[itc2] ? itc1 : itc2);
			}
		}
	}
	int query(int i, int j) {
		int ltf = log2(j-i+1);
		int itc1 = table[ltf][i];
		int itc2 = table[ltf][j-(1<<ltf)+1];
		return (arr[itc1] < arr[itc2] ? itc1 : itc2);
	}
};

class LCAFinder {
	int n;
	vector<vector<int>> tree;
	vector<int> eTour;
public:
	vector<int> postOrder;
	vector<int> parents;
private:
	vector<int> enterT;
	vector<int> etLevel;
	vector<int> ccID;
	SparseTable minFinder;
	void fillCC(int i, int p, int curccID, int cLevel) {
		enterT[i] = eTour.size();
		parents[i] = p;
		eTour.push_back(i);
		etLevel.push_back(cLevel);
		ccID[i] = curccID;
		for (int next : tree[i]) {
			if (next != p) {
				fillCC(next, i, curccID, cLevel + 1);
				eTour.push_back(i);
				etLevel.push_back(cLevel);
			}
		}
		postOrder.push_back(i);
	}
public:
	LCAFinder() {}
	LCAFinder(vector<vector<int>> ot) : n(ot.size()), tree(ot) {
		eTour.reserve(2*n);
		etLevel.reserve(2*n);
		enterT = parents = vector<int>(n, -1);
		ccID = vector<int>(n, 0);
		for (int i = 0; i < n; ++i) {
			if (enterT[i] == -1) {
				fillCC(i, -1, i, 0);
			}
		}
		minFinder = SparseTable(etLevel);
	}
	int query(int i, int j) {
		if (ccID[i] != ccID[j]) {
			return -1;
		} else {
			if (enterT[i] > enterT[j]) {
				return query(j, i);
			}
			return eTour[minFinder.query(enterT[i], enterT[j])];
		}
	}
};

vector<vector<pair<int, int>>> graph;
vector<pair<int, int>> edgeList;
vector<bool> isBridge;
vector<int> low;
vector<int> disc;
vector<bool> exemptFromB;
int t = 0;

void popBL(int i, int p) {
	low[i] = t;
	disc[i] = t++;
	for (auto next_id : graph[i]) {
		if (disc[next_id.first] == -1) {
			popBL(next_id.first, i);
			low[i] = min(low[i], low[next_id.first]);
			if (low[next_id.first] > disc[i] && !exemptFromB[next_id.second]) {
				isBridge[next_id.second] = true;
			}
		} else if (next_id.first != p) {
			low[i] = min(low[i], disc[next_id.first]);
		}
	}
}

int main() {
	int n, m, q; scanf("%d %d %d", &n, &m, &q);
	graph = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
	edgeList = vector<pair<int, int>>();
	edgeList.reserve(m);
	isBridge = exemptFromB = vector<bool>(m, false);
	low = disc = vector<int>(n, -1);
	set<pair<int, int>> edgeSet;
	set<pair<int, int>> repeats;
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		graph[--u].emplace_back(--v, i);
		graph[v].emplace_back(u, i);
		edgeList.emplace_back(u, v);
		if (edgeSet.count({u, v}) > 0) {
			repeats.insert({v, u});
			repeats.insert({u, v});
		}
		edgeSet.insert({u, v});
		edgeSet.insert({v, u});
	}
	for (int i = 0; i < m; ++i) {
		if (repeats.count(edgeList[i]) > 0) {
			exemptFromB[i] = true;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (disc[i] == -1) {
			popBL(i, -1);
		}
	}
	vector<int> btComp(n, 0);
	int cBTCompID = 0;
	vector<bool> btcSVis(n, false);
	for (int i = 0; i < n; ++i) {
		if (!btcSVis[i]) {
			btcSVis[i] = true;
			queue<int> btq;
			btq.push(i);
			while (!btq.empty()) {
				int cur = btq.front(); btq.pop();
				btComp[cur] = cBTCompID;
				//printf("%d in BrCC %d\n", cur, btComp[cur]);
				for (auto next_id : graph[cur]) {
					if (!btcSVis[next_id.first] && !isBridge[next_id.second]) {
						btcSVis[next_id.first] = true;
						btq.push(next_id.first);
					}
				}
			}
			++cBTCompID;
		}
	}
	vector<vector<int>> bTree(cBTCompID, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (auto next_id : graph[i]) {
			int next = next_id.first;
			if (btComp[i] != btComp[next]) {
				//printf("bte %d-%d\n", btComp[i], btComp[next]);
				bTree[btComp[i]].push_back(btComp[next]);
			}
		}
	}
	LCAFinder finally(bTree);
	vector<int> upward(cBTCompID, 0);
	vector<int> downward(cBTCompID, 0);
	bool allPairsConnected = true;
	for (int i = 0; i < q; ++i) {
		int s, d; scanf("%d %d", &s, &d);
		int bts = btComp[--s];
		int btd = btComp[--d];
		//printf("path %d->%d\n", bts, btd);
		int r = finally.query(bts, btd);
		//printf("BrCC path %d->%d->%d\n", bts, r, btd);
		if (r == -1) {
			allPairsConnected = false;
		} else {
			++upward[bts];
			--upward[r];
			++downward[btd];
			--downward[r];
		}
	}
	if (!allPairsConnected) {
		printf("No\n");
		return 0;
	}
	for (int i : finally.postOrder) {
		for (int next : bTree[i]) {
			if (next != finally.parents[i]) {
				upward[i] += upward[next];
				downward[i] += downward[next];
			}
		}
	}
	for (int i = 0; i < cBTCompID; ++i) {
		//printf("u d %d = %d %d\n", i, upward[i], downward[i]);
		if (upward[i] > 0 && downward[i] > 0) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}