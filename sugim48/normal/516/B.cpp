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
int INF = INT_MAX / 4;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
	int n, m; cin >> n >> m;
	vector<string> a(n);
	for (int y = 0; y < n; y++)
		cin >> a[y];
	vector<vector<int> > d(n, vector<int>(m));
	stack<i_i> st;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			if (a[y][x] != '.') continue;
			for (int k = 0; k < 4; k++) {
				int _x = x + dx[k], _y = y + dy[k];
				if (_x >= 0 && _x < m && _y >= 0 && _y < n && a[_y][_x] == '.')
					d[y][x]++;
			}
			if (d[y][x] == 0) {
				cout << "Not unique" << endl;
				return 0;
			}
			if (d[y][x] == 1) st.push(i_i(x, y));
		}
	while (!st.empty()) {
		i_i p = st.top(); st.pop();
		int x = p.first, y = p.second;
		if (a[y][x] != '.') continue;
		if (d[y][x] == 0) {
			cout << "Not unique" << endl;
			return 0;
		}
		for (int k = 0; k < 4; k++) {
			int _x = x + dx[k], _y = y + dy[k];
			if (_x < 0 || _x >= m || _y < 0 || _y >= n || a[_y][_x] != '.') continue;
			if (k == 0) { a[y][x] = '>'; a[_y][_x] = '<'; }
			if (k == 1) { a[y][x] = 'v'; a[_y][_x] = '^'; }
			if (k == 2) { a[y][x] = '<'; a[_y][_x] = '>'; }
			if (k == 3) { a[y][x] = '^'; a[_y][_x] = 'v'; }
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n || a[ny][nx] != '.') continue;
				d[ny][nx]--;
				if (d[ny][nx] == 0) {
					cout << "Not unique" << endl;
					return 0;
				}
				if (d[ny][nx] == 1) st.push(i_i(nx, ny));
			}
			for (int k = 0; k < 4; k++) {
				int nx = _x + dx[k], ny = _y + dy[k];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n || a[ny][nx] != '.') continue;
				d[ny][nx]--;
				if (d[ny][nx] == 0) {
					cout << "Not unique" << endl;
					return 0;
				}
				if (d[ny][nx] == 1) st.push(i_i(nx, ny));
			}
		}
	}
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			if (a[y][x] == '.') {
				cout << "Not unique" << endl;
				return 0;
			}
	for (int y = 0; y < n; y++)
		cout << a[y] << endl;
}