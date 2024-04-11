
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
vector<int> adj[N];
int c[N];
int gcd(int x, int y) {
	if (min(x, y) == 0) return x + y;
	return gcd(y, x % y);
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < n; ++j) cin >> c[j];
		for (int j = 0; j < m; ++j) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			adj[v].pb(u);
		}
		map<vector<int>, int> score;
		for (int v = 0; v < n; ++v) {
			sort(ALL(adj[v]));
			if (adj[v].size() > 0)
				score[adj[v]] += c[v];
			adj[v].clear();
		}
		int g = 0;
		for (auto x : score) {
			int cur = x.second;
			g = gcd(cur, g);
		}
		cout << g << '\n';
	}
}