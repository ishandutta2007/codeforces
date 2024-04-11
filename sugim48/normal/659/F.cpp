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

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return (v[x] < 0) ? x : (v[x] = find(v[x])); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (-v[x] < -v[y]) swap(x, y);
			v[x] += v[y]; v[y] = x;
		}
	}
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int H, W, cnt, unko;

void dfs(int y, int x, int i, vector<vector<int> >& a, vector<vector<bool> >& vis) {
	if (vis[y][x] || cnt == unko) return;
	vis[y][x] = true;
	cnt++;
	for (int k = 0; k < 4; k++) {
		int _y = y + dy[k], _x = x + dx[k];
		if (0 <= _y && _y < H && 0 <= _x && _x < W && a[_y][_x] >= i)
			dfs(_y, _x, i, a, vis);
	}
}

int main() {
	cin >> H >> W;
	ll K; cin >> K;
	vector<vector<int> > a(H, vector<int>(W));
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			scanf("%d", &a[y][x]);
	vector<int> v;
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			v.push_back(a[y][x]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int n = v.size();
	vector<vector<i_i> > b(n);
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++) {
			a[y][x] = lower_bound(v.begin(), v.end(), a[y][x]) - v.begin();
			b[a[y][x]].push_back(i_i(y, x));
		}
	union_find uf(H * W);
	int ma = 0;
	for (int i = n - 1; i >= 0; i--) {
		int z = v[i];
		for (i_i yx: b[i]) {
			int y = yx.first, x = yx.second;
			for (int k = 0; k < 4; k++) {
				int _y = y + dy[k], _x = x + dx[k];
				if (0 <= _y && _y < H && 0 <= _x && _x < W && a[_y][_x] >= i)
					uf.unite(y * W + x, _y * W + _x);
				ma = max(ma, uf.size(y * W + x));
			}
		}
		if (K % z == 0 && ma >= K / z) {
			vector<vector<bool> > vis(H, vector<bool>(W));
			cnt = 0; unko = K / z;
			for (int y = 0; y < H; y++)
				for (int x = 0; x < W; x++)
					if (a[y][x] == i && uf.size(y * W + x) >= K / z) {
						dfs(y, x, i, a, vis);
						break;
					}
			cout << "YES" << endl;
			for (int y = 0; y < H; y++) {
				for (int x = 0; x < W; x++)
					printf("%d ", vis[y][x] ? z : 0);
				cout << endl;
			}
			return 0;
		}
	}
	cout << "NO" << endl;
}