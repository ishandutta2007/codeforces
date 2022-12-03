#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

void dfs(int u, bool x, vector<vector<bool> >& a, string& s) {
	if (s[u] != 'b') return;
	s[u] = (x ? 'a' : 'c');
	int n = a.size();
	for (int v = 0; v < n; v++)
		if (!a[u][v])
			dfs(v, !x, a, s);
}

int main() {
	int n, m; cin >> n >> m;
	vector<vector<bool> > a(n, vector<bool>(n));
	while (m--) {
		int u, v; cin >> u >> v;
		u--; v--;
		a[u][v] = a[v][u] = true;
	}
	string s(n, 'b');
	for (int u = 0; u < n; u++)
		for (int v = u + 1; v < n; v++)
			if (!a[u][v]) {
				dfs(u, true, a, s);
				goto L;
			}
L:;
	bool ok = true;
	for (int u = 0; u < n; u++)
		for (int v = u + 1; v < n; v++) {
			int x = abs(s[u] - s[v]);
			if (!((a[u][v] && x <= 1) || (!a[u][v] && x == 2)))
				ok = false;
		}
	if (ok) {
		cout << "Yes" << endl;
		cout << s << endl;
	}
	else cout << "No" << endl;
}