#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> z(k);
	for (int i = 0; i < k; i++) {
		cin >> z[i];
		z[i]--;
	}
	vector<vector<int> > G(n);
	vector<int> d(n);
	while (m--) {
		int a, b; scanf("%d%d", &a, &b);
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
		d[a]++; d[b]++;
	}
	vector<int> ans;
	double lb = -1, ub = 2;
	for (int t = 0; t < 100; t++) {
		double mid = (lb + ub) / 2;
		vector<int> _d = d;
		queue<int> q;
		for (int i = 0; i < k; i++) {
			_d[z[i]] = -1;
			q.push(z[i]);
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < G[u].size(); i++) {
				int v = G[u][i];
				if (_d[v] == -1) continue;
				_d[v]--;
				if (_d[v] < d[v] * mid) {
					_d[v] = -1;
					q.push(v);
				}
			}
		}
		bool ok = false;
		for (int u = 0; u < n; u++)
			if (_d[u] != -1)
				ok = true;
		if (ok) lb = mid;
		else ub = mid;
		if (ok) {
			ans.clear();
			for (int u = 0; u < n; u++)
				if (_d[u] != -1)
					ans.push_back(u);
		}
	}
	int r = ans.size();
	cout << r << endl;
	for (int i = 0; i < r; i++)
		printf("%d ", ans[i] + 1);
	cout << endl;
}