#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

vector<vector<int>> g;
int h[200100];
int sz[200100];
bool used[200100];

void dfs(int v, int cur_h = 0) {
	used[v] = true;
	sz[v] = 1;
	h[v] = cur_h;
	for (int to: g[v]) {
		if (!used[to]) {
			dfs(to, cur_h + 1);
			sz[v] += sz[to];
		}
	}
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    g.resize(n);
    forn (i, n - 1) {
    	int a, b;
    	cin >> a >> b;
    	--a; --b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    dfs(0);
    int ans = 0;
    vector<int> x;
    forn (i, n) {
    	x.push_back(sz[i] - h[i] - 1);
    }
    sort(x.begin(), x.end());
    forn (i, k) {
    	ans -= x[i];
    }
    cout << ans << endl;
}