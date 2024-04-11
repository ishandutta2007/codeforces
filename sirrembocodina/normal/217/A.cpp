#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define forab(i, a, b) for (int i = a; i < int(b); ++i)
#define fordab(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())
#define pb push_back

typedef long long int64;

vector<int> g[2100];
bool used[2100];

void dfs(int v) {
	used[v] = true;
	forv (i, g[v]) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
		}
	}
}

int main() {
	int n;
	cin >> n;
	forn (i, 2100) {
		used[i] = false;
	}
	forn (i, n) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		y += 1000;
		g[x].pb(y);
		g[y].pb(x);
	}
	int ans = -1;
	forn (i, 1000) {
		if (g[i].size() && !used[i]) {
			dfs(i);
			++ans;
		}
	}
	cout << max(0, ans);
}