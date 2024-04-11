#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int maxN = 110;
int n, m;
set < int > g[maxN];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	int res = 0;
	while (true) {
		vector < int > a;
		for (int i = 1; i <= n; ++i) {
			if (g[i].size() == 1) {
				a.push_back(i);
			}
		}
		if (a.size() > 0) {
			++res;
		} else {
			break;
		}
		for (int i = 0; i < a.size(); ++i) {
			g[*g[a[i]].begin()].erase(a[i]);
			g[a[i]].clear();
		}
	}
	cout << res << endl;
	return 0;
}