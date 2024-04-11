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
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

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
short INF = 20000;
double EPS = 1e-10;

int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main() {
	int N; cin >> N;
	vector<int> t(N);
	rep(i, N) cin >> t[i];
	vector<vector<vector<bool> > > a(320, vector<vector<bool> >(320, vector<bool>(8)));
	a[160][160][2] = true;
	vector<vector<vector<int> > > b(320, vector<vector<int> >(320, vector<int>(8)));
	rep(i, N) {
		rep(y, 320) rep(x, 320) rep(k, 8) if (a[y][x][k])
			b[y][x][k] = max(b[y][x][k], t[i]);
		vector<vector<vector<bool> > > _a(320, vector<vector<bool> >(320, vector<bool>(8)));
		rep(y, 320) rep(x, 320) rep(k, 8) if (a[y][x][k]) {
			int _y = y + dy[k] * t[i], _x = x + dx[k] * t[i];
			_a[_y][_x][(k + 1) % 8] = _a[_y][_x][(k + 7) % 8] = true;
		}
		a = _a;
	}
	vector<vector<bool> > c(320, vector<bool>(320));
	rep(y, 320) rep(x, 320) rep(k, 8) rep(t, b[y][x][k])
		c[y + dy[k] * (t + 1)][x + dx[k] * (t + 1)] = true;
	int ans = 0;
	rep(y, 320) rep(x, 320) ans += c[y][x];
	cout << ans << endl;
}