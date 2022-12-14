
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
int s[2], h[N];
vector<int> adj[N];
void dfs(int v, int p = -1) {
	h[v] = (p == -1 ? 0 : h[p] + 1);
	for (int u : adj[v]) if (u != p) {
		dfs(u, v);	
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0);
	for (int v = 0; v < n; ++v)
		s[h[v] & 1]++;
	cout << min(s[0], s[1]) - 1 << endl;
}