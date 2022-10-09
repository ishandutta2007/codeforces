#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

vector<int> g[1010];
int c[1010];
bool used[1010];
int col[1010];
int csz[1010];

void dfs(int v, int c) {
	used[v] = true;
	col[v] = c;
	csz[c]++;
	forn (i, g[v].size()) {
		if (used[g[v][i]]) {
			continue;
		}
		dfs(g[v][i], c);
	}
}

int main() {
	ios_base::sync_with_stdio();
	int n, m, k;
	cin >> n >> m >> k;
	forn (i, k) {
		cin >> c[i];
		--c[i];
	}
	forn (i, m) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ind = 0;
	forn (i, k) {
		dfs(c[i], i);
		if (csz[i] > csz[ind]) {
			ind = i;
		}
	}
	forn (i, n) {
		if (!used[i]) {
			csz[ind]++;
		}
	}
	long long ans = 0;
	forn (i, k) {
//		cerr << csz[i] << " ";
		ans += (csz[i] * (csz[i] - 1)) / 2;
	}
	cout << ans - m;
}