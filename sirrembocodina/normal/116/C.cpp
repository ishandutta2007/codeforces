#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(a) a.begin(), a.end()

vector<vector<int> > g;
vector<int> r;
vector<bool> used;
int ans = 0;

void dfs(int v, int h) {
	used[v] = true;
	ans = max(ans, h);
	forn (i, g[v].size()) {
		dfs(g[v][i], h + 1);
	}
}

int main() {
	int n;
	cin >> n;
	g.resize(n);
	forn (i, n) {
		int x;
		cin >> x;
		x--;
		if (x != -2) {
			g[x].pb(i);
		} else {
			r.pb(i);
		}
	}
	used.assign(n, false);
	forn (i, r.size()) {
		dfs(r[i], 1);
	}
	cout << ans;
}