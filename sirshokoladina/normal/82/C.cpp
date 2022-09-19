#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define pb push_back

int prior[10000];

vector<int> e0[10000], c0[10000];
int p[10000], c[10000];
vector<int> num[2][10000];

void dfs(int u, int v) {
	forn (i, e0[u].size()) {
		if (e0[u][i] != v) {
			p[e0[u][i]] = u;
			c[e0[u][i]] = c0[u][i];
			dfs(e0[u][i], u);
		}
	}
}

bool func(int a, int b) {
	return prior[a] < prior[b];
}

int ans[10000];

int main() {
	int n;
	cin >> n;
	forn (i, n) {
		scanf("%d", &prior[i]);
	}
	forn (i, n - 1) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--, y--;
		e0[x].pb(y);
		c0[x].pb(z);
		e0[y].pb(x);
		c0[y].pb(z);
	}
	dfs(0, 0);
	bool q = 1;
	bool w = 0;
	forn (i, n) {
		num[0][i].pb(i);
		ans[i] = 0;
	}
	while (q) {
//		cerr << endl;
//		forn (i, n) {
//			forn (j, num[w][i].size()) {
//				cerr << num[w][i][j] << ' ';
//			}
//			cerr << endl;
//		}
//		cerr << endl;
		forn (i, n) {
			num[w ^ 1][i].clear();
		}
		num[w ^ 1][0] = num[w][0];
		q = 0;
		for (int i = 1; i < n; i++) {
			sort(num[w][i].begin(), num[w][i].end(), func);
			forn (j, num[w][i].size()) {
				if (j < c[i]) {
					num[w ^ 1][p[i]].pb(num[w][i][j]);
				} else {
					num[w ^ 1][i].pb(num[w][i][j]);
				}
				ans[num[w][i][j]]++;
				q = 1;
			}
		}
		w ^= 1;
	}
	forn (i, n) {
		cout << ans[i] << ' ';
	}
}