#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
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

int calc(int n, int m, vector< vector<bool> >& a) {
	vector<int> l(n, -1), r(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if ((j == 0 || !a[i][j - 1]) && a[i][j]) {
				if (l[i] == -1) l[i] = j;
				else return INT_MAX;
			}
		for (int j = m; j > 0; j--)
			if ((j == m || !a[i][j]) && a[i][j - 1]) {
				if (r[i] == -1) r[i] = j;
				else return INT_MAX;
			}
	}
	int u = -1, d = -1;
	for (int i = 0; i < n; i++)
		if ((i == 0 || l[i - 1] == -1) && l[i] != -1) {
			if (u == -1) u = i;
			else return INT_MAX;
		}
	for (int i = n; i > 0; i--)
		if ((i == n || l[i] == -1) && l[i - 1] != -1) {
			if (d == -1) d = i;
			else return INT_MAX;
		}
	for (int i = u; i < d - 1; i++)
		if (l[i] > l[i + 1] || r[i] > r[i + 1]) return INT_MAX;
	int w = r[u] - l[u];
	for (int h = 1; h <= d - u; h++) {
		bool flag = true;
		for (int i = u; i < u + h - 1; i++)
			if (l[i] < l[i + 1]) flag = false;
		for (int i = d - h; i < d - 1; i++)
			if (r[i] < r[i + 1]) flag = false;
		for (int i = u + h; i < d; i++)
			if (r[i - h] - l[i] != w) flag = false;
		if (flag) return h * w;
	}
	return INT_MAX;
}

int main() {
	int n, m; cin >> n >> m;
	vector< vector<bool> > a(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++)
			a[i][j] = (s[j] == 'X');
	}
	int x = calc(n, m, a);
	vector< vector<bool> > _a(m, vector<bool>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			_a[j][i] = a[i][j];
	int y = calc(m, n, _a);
	int ans = min(x, y);
	cout << (ans < INT_MAX ? ans : -1) << endl;
}