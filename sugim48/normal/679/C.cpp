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
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

int dy[] = {0, -1, 0, 1, 0};
int dx[] = {-1, 0, 1, 0, 0};

int N, M, K = 0;
int unko = 0, ans = 0;

char s[510];
bool a[500][500];
int sum[501][501], c[500][500];
int sz[250000], inside[250000];

void dfs(int y, int x, int k) {
	c[y][x] = k;
	sz[k]++;
	rep(d, 4) {
		int _y = y + dy[d], _x = x + dx[d];
		if (0 <= _y && _y < N && 0 <= _x && _x < N && a[_y][_x] && c[_y][_x] == -1)
			dfs(_y, _x, k);
	}
}

void add(int y, int x) {
	rep(d, 5) {
		int _y = y + dy[d], _x = x + dx[d];
		if (0 <= _y && _y < N && 0 <= _x && _x < N && c[_y][_x] != -1) {
			int k = c[_y][_x];
			if (!inside[k]) unko += sz[k];
			inside[k]++;
		}
	}
}

void remove(int y, int x) {
	rep(d, 5) {
		int _y = y + dy[d], _x = x + dx[d];
		if (0 <= _y && _y < N && 0 <= _x && _x < N && c[_y][_x] != -1) {
			int k = c[_y][_x];
			inside[k]--;
			if (!inside[k]) unko -= sz[k];
		}
	}
}

int main() {
	cin >> N >> M;
	rep(y, N) {
		scanf("%s", s);
		rep(x, N) a[y][x] = (s[x] == '.');
	}
	rep(y, N) rep(x, N)
		sum[y + 1][x + 1] = sum[y + 1][x] + sum[y][x + 1] - sum[y][x] + !a[y][x];
	rep(y, N) rep(x, N) c[y][x] = -1;
	rep(y, N) rep(x, N) if (a[y][x] && c[y][x] == -1) dfs(y, x, K++);
	for (int y0 = 0; y0 + M <= N; y0++) {
		rep(y, M) rep(x, M) add(y0 + y, x);
		ans = max(ans, unko + sum[y0 + M][M] - sum[y0 + M][0] - sum[y0][M] + sum[y0][0]);
		for (int x0 = 1; x0 + M <= N; x0++) {
			rep(y, M) remove(y0 + y, x0 - 1);
			rep(y, M) add(y0 + y, x0 + M - 1);
			ans = max(ans, unko + sum[y0 + M][x0 + M] - sum[y0 + M][x0] - sum[y0][x0 + M] + sum[y0][x0]);
		}
		rep(y, M) rep(x, M) remove(y0 + y, N - 1 - x);
	}
	cout << ans << endl;
}