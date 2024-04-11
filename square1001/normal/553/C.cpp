#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
struct edge { int to, c; };
int n, m, a, b, c, col[100009]; bool f = true; vector<edge> g[100009];
void dfs(int pos) {
	for (edge e : g[pos]) {
		if (col[e.to] == -1) {
			col[e.to] = col[pos] ^ e.c;
			dfs(e.to);
		}
		else if (col[e.to] != col[pos] ^ e.c) f = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c; a--, b--;
		g[a].push_back(edge{ b, c ^ 1 });
		g[b].push_back(edge{ a, c ^ 1 });
	}
	fill(col, col + n, -1);
	int ret = 1, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (col[i] == -1) {
			col[i] = 0;
			dfs(i);
			if(cnt++) ret = ret * 2 % mod;
		}
	}
	cout << (f ? ret : 0) << endl;
	return 0;
}