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
double INF = FLT_MAX;

int main() {
	int h, w; cin >> h >> w;
	vector<string> s(h);
	for (int y = 0; y < h; y++)
		cin >> s[y];
	vector<vector<bool> > a(h, vector<bool>(w));
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			a[y][x] = (s[y][x] == '.');
	vector<vector<int> > sum(h + 1, vector<int>(w + 1));
	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++) {
			sum[y][x] = sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1];
			if (y >= 2 && a[y - 2][x - 1] && a[y - 1][x - 1]) sum[y][x]++;
			if (x >= 2 && a[y - 1][x - 2] && a[y - 1][x - 1]) sum[y][x]++;
		}
	int q; cin >> q;
	while (q--) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		r1--; c1--;
		int ans = sum[r2][c2] - sum[r1][c2] - sum[r2][c1] + sum[r1][c1];
		if (r1)
			for (int x = c1; x < c2; x++)
				if (a[r1 - 1][x] && a[r1][x])
					ans--;
		if (c1)
			for (int y = r1; y < r2; y++)
				if (a[y][c1 - 1] && a[y][c1])
					ans--;
		printf("%d\n", ans);
	}
}