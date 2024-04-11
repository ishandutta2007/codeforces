#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, long long> edge;
int n, k;
vector< vector<edge> > adjlist;
vector<int> parent;
vector<long long> dptable[2];
void dfs(int v, int p) {
	parent[v] = p;
	for (edge i: adjlist[v]) {
		if (i.first == p) continue;
		dfs(i.first, v);
	}
}
long long dp(bool p, int v) {
	if (dptable[p][v] != -1) return dptable[p][v];
	int maxtake;
	if (v == 0) maxtake = min(k - p, (int) adjlist[v].size());
	else maxtake = min(k - p, (int) adjlist[v].size() - 1);
	long long ans = 0;
	priority_queue<long long> imp;
	for (edge i: adjlist[v]) {
		if (i.first == parent[v]) continue;
		ans += dp(0, i.first);
		imp.push(dp(1, i.first) + i.second - dp(0, i.first));
	}
	while (maxtake != 0 && imp.top() > 0) {
		ans += imp.top();
		imp.pop();
		--maxtake;
	}
	return dptable[p][v] = ans;
}
int main() {
	int q, u, v;
	long long w;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d %d", &n, &k);
		adjlist = vector< vector<edge> >(n);
		parent = vector<int>(n);
		dptable[0] = vector<long long>(n, -1);
		dptable[1] = vector<long long>(n, -1);
		for (int j = 1; j < n; ++j) {
			scanf("%d %d %lld", &u, &v, &w);
			adjlist[u - 1].push_back(edge(v - 1, w));
			adjlist[v - 1].push_back(edge(u - 1, w));
		}
		dfs(0, -1);
		printf("%lld\n", dp(0, 0));
	}
	return 0;
}