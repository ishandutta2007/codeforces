#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct edge { int to, id; };
int n, a, b, r; vector<edge> g[200009]; vector<int> ret[200009];
void dfs(int pos, int pre, int pid) {
	int curid = 0;
	for (edge e : g[pos]) {
		if (e.to != pre) {
			if (pid == curid) curid++;
			ret[curid].push_back(e.id);
			dfs(e.to, pos, curid);
			curid++;
		}
	}
	r = max(r, curid);
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b; a--, b--;
		g[a].push_back(edge{ b, i });
		g[b].push_back(edge{ a, i });
	}
	dfs(0, -1, -1);
	cout << r << endl;
	for (int i = 0; i < r; i++) {
		cout << ret[i].size();
		for (int j : ret[i]) cout << ' ' << j;
		cout << endl;
	}
	return 0;
}