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
#include <list>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 10007;
ll _MOD = 1000000009;
double EPS = 1e-10;

vector<i_i> f(int y, int x, int h, int w, vector<vector<i_i> >& down, vector<vector<i_i> >& right) {
	vector<i_i> p;
	int i = 0, j = 0;
	while (y--) {
		i_i yx = down[i][j];
		i = yx.first; j = yx.second;
	}
	while (x--) {
		i_i yx = right[i][j];
		i = yx.first; j = yx.second;
	}
	int i0 = i, j0 = j;
	{
		int i = i0, j = j0;
		for (int t = 0; t < h; t++) {
			i_i yx = down[i][j];
			i = yx.first; j = yx.second;
			p.push_back(i_i(~i, j));
		}
		for (int t = 0; t < w; t++) {
			i_i yx = right[i][j];
			i = yx.first; j = yx.second;
			p.push_back(i_i(i, j));
		}
	}
	{
		int i = i0, j = j0;
		for (int t = 0; t < w; t++) {
			i_i yx = right[i][j];
			i = yx.first; j = yx.second;
			p.push_back(i_i(i, j));
		}
		for (int t = 0; t < h; t++) {
			i_i yx = down[i][j];
			i = yx.first; j = yx.second;
			p.push_back(i_i(~i, j));
		}
	}
	return p;
}

int main() {
	int H, W, Q; cin >> H >> W >> Q;
	vector<vector<int> > a(H, vector<int>(W));
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			scanf("%d", &a[y][x]);
	vector<vector<i_i> > down(H + 1, vector<i_i>(W + 1)), right = down;
	for (int y = 0; y <= H; y++)
		for (int x = 0; x <= W; x++) {
			down[y][x] = i_i(y + 1, x);
			right[y][x] = i_i(y, x + 1);
		}
	while (Q--) {
		int y1, x1, y2, x2, h, w;
		scanf("%d%d%d%d%d%d", &y1, &x1, &y2, &x2, &h, &w);
		vector<i_i> ps1 = f(y1 - 1, x1 - 1, h, w, down, right);
		vector<i_i> ps2 = f(y2 - 1, x2 - 1, h, w, down, right);
		for (int k = 0; k < ps1.size(); k++) {
			i_i p1 = ps1[k], p2 = ps2[k];
			if (p1.first >= 0)
				swap(down[p1.first][p1.second], down[p2.first][p2.second]);
			else {
				p1.first = ~p1.first;
				p2.first = ~p2.first;
				swap(right[p1.first][p1.second], right[p2.first][p2.second]);
			}
		}
	}
	for (int y = 0; y < H; y++) {
		int i = y + 1, j = 0;
		for (int x = 0; x < W; x++) {
			i_i yx = right[i][j];
			i = yx.first; j = yx.second;
			printf("%d ", a[i - 1][j - 1]);
		}
		cout << endl;
	}
}