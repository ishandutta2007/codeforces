#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <map>
#include <queue>
#include <random>
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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int> > G(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<vector<int> > d(n, vector<int>(n, INT_MAX));
	for (int u = 0; u < n; u++) {
		d[u][u] = 0;
		queue<int> q;
		q.push(u);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int i = 0; i < G[v].size(); i++) {
				int w = G[v][i];
				if (d[u][w] > d[u][v] + 1) {
					d[u][w] = d[u][v] + 1;
					q.push(w);
				}
			}
		}
	}
	int s1, t1, l1; cin >> s1 >> t1 >> l1;
	s1--; t1--;
	int s2, t2, l2; cin >> s2 >> t2 >> l2;
	s2--; t2--;
	int mini = INT_MAX;
	if (d[s1][t1] <= l1 && d[s2][t2] <= l2)
		mini = min(mini, d[s1][t1] + d[s2][t2]);
	for (int u = 0; u < n; u++)
		for (int v = 0; v < n; v++) {
			int x1, x2;
			x1 = d[s1][u] + d[u][v] + d[v][t1];
			x2 = d[s2][u] + d[u][v] + d[v][t2];
			if (x1 <= l1 && x2 <= l2)
				mini = min(mini, x1 + x2 - d[u][v]);
			x1 = d[s1][u] + d[u][v] + d[v][t1];
			x2 = d[t2][u] + d[u][v] + d[v][s2];
			if (x1 <= l1 && x2 <= l2)
				mini = min(mini, x1 + x2 - d[u][v]);
		}
	cout << (mini < INT_MAX ? m - mini : -1) << endl;
}