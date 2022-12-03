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
double EPS = 1e-10;
int INF = INT_MAX / 2;

bool f(vector<string> a) {
	int H = a.size(), W = a[0].length();
	int ys, xs, yt, xt;
	rep(y, H) rep(x, W) {
		if (a[y][x] == 'S') ys = y, xs = x;
		if (a[y][x] == 'T') yt = y, xt = x;
		if (a[y][x] != '*') a[y][x] = '.';
	}
	vector<vector<bool> > b(H, vector<bool>(W));
	b[ys][xs] = true;
	rep(y, H) {
		for (int x = 0; x + 1 < W; x++)
			if (b[y][x] && a[y][x + 1] == '.')
				b[y][x + 1] = true;
		for (int x = W - 1; x - 1 >= 0; x--)
			if (b[y][x] && a[y][x - 1] == '.')
				b[y][x - 1] = true;
	}
	rep(x, W) {
		for (int y = 0; y + 1 < H; y++)
			if (b[y][x] && a[y + 1][x] == '.')
				b[y + 1][x] = true;
		for (int y = H - 1; y - 1 >= 0; y--)
			if (b[y][x] && a[y - 1][x] == '.')
				b[y - 1][x] = true;
	}
	rep(y, H) {
		for (int x = 0; x + 1 < W; x++)
			if (b[y][x] && a[y][x + 1] == '.')
				b[y][x + 1] = true;
		for (int x = W - 1; x - 1 >= 0; x--)
			if (b[y][x] && a[y][x - 1] == '.')
				b[y][x - 1] = true;
	}
	return b[yt][xt];
}

int main() {
	int H, W; cin >> H >> W;
	vector<string> a(H);
	rep(y, H) cin >> a[y];
	vector<string> _a(W, string(H, ' '));
	rep(y, H) rep(x, W)
		_a[x][y] = a[y][x];
	cout << (f(a) || f(_a) ? "YES" : "NO") << endl;
}