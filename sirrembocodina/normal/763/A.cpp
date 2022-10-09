#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define fs first
#define sc second

vector<int> g[100100];
int c[100100];
int sz[100100];
bool used[100100];
bool used2[100100];
int g_sz = 0;

void dfs(int v) {
	used[v] = true;
	g_sz++;
	forn (i, g[v].size()) {
		if (used[g[v][i]] || c[v] != c[g[v][i]]) {
			continue;
		}
		dfs(g[v][i]);
	}
}

void dfs2(int v) {
	used2[v] = true;
	sz[v] = g_sz;
	forn (i, g[v].size()) {
		if (used2[g[v][i]] || c[v] != c[g[v][i]]) {
			continue;
		}
		dfs2(g[v][i]);
	}
}

int main() {
	int n;
	cin >> n;
	forn (i, n - 1) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	forn (i, n) {
		cin >> c[i];
	}
	forn (i, n) {
		if (used[i]) {
			continue;
		}
		g_sz = 0;
		dfs(i);
		dfs2(i);
	}
	forn (i, n) {
		int cur = sz[i];
		forn (j, g[i].size()) {
			if (c[i] != c[g[i][j]]) {
				cur += sz[g[i][j]];
			}
		}
		if (cur == n) {
			cout << "YES\n" << i + 1 << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}