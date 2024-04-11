
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

const int N = (int) 1005, mod = (int) 0;
vector<int> adj[N];
int deg[N], q[N], h, t;
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	for (int v = 0; v < n; ++v)
		if (deg[v] == 1)
			q[t++] = v;
	while (t - h > 1) {
		int u = q[h++];
		int v = q[h++];
		cout << "? " << u+1 << ' ' << v+1 << endl;
		int x;
		cin >> x;
		--x;
		if (x == u) {
			cout << "! " << u+1 << endl;
			return 0;
		}
		if (x == v) {
			cout << "! " << v+1 << endl;
			return 0;
		}
		for (int w : adj[u]) {
			--deg[w];
			if (deg[w] == 1) q[t++] = w;
		}
		for (int w : adj[v]) {
			--deg[w];
			if (deg[w] == 1) q[t++] = w;
		}
	}
	cout << "! " << q[h] + 1 << endl;
}