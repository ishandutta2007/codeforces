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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
	int n, m; cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ys, xs; cin >> ys >> xs; ys--; xs--;
	int yt, xt; cin >> yt >> xt; yt--; xt--;
	if (xs == xt && ys == yt) {
		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			int _x = xt + dx[k], _y = yt + dy[k];
			if (_x >= 0 && _x < m && _y >= 0 && _y < n && a[_y][_x] == '.')
				cnt++;
		}
		cout << (cnt ? "YES" : "NO") << endl;
		return 0;
	}
	vector<vector<bool> > vis(n, vector<bool>(m));
	vis[ys][xs] = true;
	stack<int> X, Y;
	X.push(xs); Y.push(ys);
	while (!X.empty()) {
		int x = X.top(); X.pop();
		int y = Y.top(); Y.pop();
		for (int k = 0; k < 4; k++) {
			int _x = x + dx[k], _y = y + dy[k];
			if (_x >= 0 && _x < m && _y >= 0 && _y < n) {
				if (a[_y][_x] == '.' && !vis[_y][_x]) {
					X.push(_x);
					Y.push(_y);
				}
				vis[_y][_x] = true;
			}
		}
	}
	if (!vis[yt][xt]) {
		cout << "NO" << endl;
		return 0;
	}
	if (a[yt][xt] == 'X') {
		cout << "YES" << endl;
		return 0;
	}
	int cnt = 0;
	for (int k = 0; k < 4; k++) {
		int _x = xt + dx[k], _y = yt + dy[k];
		if (_x >= 0 && _x < m && _y >= 0 && _y < n && a[_y][_x] == '.')
			cnt++;
	}
	if (abs(xs - xt) + abs(ys - yt) != 1)
		cnt--;
	cout << (cnt ? "YES" : "NO") << endl;
}