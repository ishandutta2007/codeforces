
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

const int N = (int) 1e6 + 6, mod = (int) 0;
vector<int> adj[N], out[N];
map<int, int> to[N];
int mark[N], h[N];
int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < n; ++j) adj[j].clear(), mark[j] = h[j] = 0, to[j].clear(), out[j].clear();
		for (int j = 0; j < m; ++j) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			to[u][v] = 1;
			to[v][u] = 1;
			out[v].pb(u);
			adj[u].pb(v);
		}
		vector<int> del;
		for (int v = 0; v < n; ++v) {
			for (int u : out[v]) if (!mark[u]) {
				h[v] = max(h[v], h[u] + 1);	
			}
			if (h[v] == 2) {
				mark[v] = 1;
				del.push_back(v);
			}
		}
		sort(ALL(del));
		del.resize(unique(ALL(del)) - del.begin());
		assert((int) del.size() * 7 <= 4 * n);
		cout << del.size() << '\n';
		for (int x : del) cout << x + 1 << ' ';
		cout << '\n';
	}
	
}