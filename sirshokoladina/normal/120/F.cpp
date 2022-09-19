#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)

vector<int> e[200];
bool u[200];

int dfs(int v) {
	if (u[v]) {
		return -10;
	}
	u[v] = 1;
	int mx = 0;
	forn (i, e[v].size()) {
		mx = max(mx, 1 + dfs(e[v][i]));
	}
	return mx;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	int ans = 0;
	forn (qqq, t) {
		forn (i, 200) {
			e[i].clear();
		}
		int n;
		cin >> n;
		forn (i, n - 1) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int mx = 0;
		forn (i, n) {
			forn (j, n) {
				u[j] = 0;
			}
			mx = max(mx, dfs(i));
		}
		ans += mx;
	}
	cout << ans;
}