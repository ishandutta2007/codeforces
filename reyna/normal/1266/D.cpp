
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
int deg[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int w, u, v;
		cin >> u >> v >> w;
		--u, --v;
		deg[u] += w;
		deg[v] -= w;
	}
	vector<int> neg, pos;
	for (int j = 0; j < n; ++j) {
		if (deg[j] < 0)
			neg.pb(j);
		else if (deg[j] > 0)
			pos.pb(j);
	}
	int pt = 0;
	vector<pair<pair<int, int>, int>> res;
	for (int x : pos) {
		while (deg[x] != 0) {
			int w = min(-deg[neg[pt]], deg[x]);
			deg[neg[pt]] += w;
			deg[x] -= w;
			res.pb(mp(mp(x, neg[pt]), w));
			if (deg[neg[pt]] == 0) ++pt;
		}
	}
	cout << (int) res.size() << '\n';
	for (auto x : res) {
		cout << x.first.first + 1 << ' ' << x.first.second + 1 << ' ' << x.second << '\n';
	}
	
}