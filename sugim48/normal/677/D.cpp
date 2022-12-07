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
struct edge { int v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 3;
double EPS = 1e-10;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int main() {
	int H, W, N; cin >> H >> W >> N;
	vector<vector<int> > a(H, vector<int>(W));
	vector<vector<i_i> > p(N + 1);
	vector<vector<int> > d(H, vector<int>(W, INF));
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++) {
			scanf("%d", &a[y][x]);
			a[y][x]--;
			p[a[y][x]].push_back(i_i(y, x));
			if (!a[y][x]) d[y][x] = y + x;
		}
	for (int i = 0; i + 1 < N; i++) {
		if (p[i].size() + p[i + 1].size() <= 300) {
			for (i_i z1: p[i])
				for (i_i z2: p[i + 1]) {
					int y1 = z1.first, x1 = z1.second;
					int y2 = z2.first, x2 = z2.second;
					d[y2][x2] = min(d[y2][x2], d[y1][x1] + abs(y2 - y1) + abs(x2 - x1));
				}
			continue;
		}
		vector<vector<int> > dp(H, vector<int>(W, INF));
		queue<i_i> q;
		for (i_i z: p[i]) {
			dp[z.first][z.second] = d[z.first][z.second];
			q.push(z);
		}
		while (!q.empty()) {
			i_i z = q.front(); q.pop();
			int y = z.first, x = z.second;
			for (int k = 0; k < 4; k++) {
				int _y = y + dy[k], _x = x + dx[k];
				if (_y >= 0 && _y < H && _x >= 0 && _x < W && dp[_y][_x] > dp[y][x] + 1) {
					dp[_y][_x] = dp[y][x] + 1;
					q.push(i_i(_y, _x));
				}
			}
		}
		for (i_i z: p[i + 1])
			d[z.first][z.second] = dp[z.first][z.second];
	}
	i_i z = p[N - 1][0];
	cout << d[z.first][z.second] << endl;
}