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

int main() {
	int n, m; cin >> n >> m;
	union_find uf(n * 2), _uf(n);
	while (m--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		a--; b--;
		if (a > b) swap(a, b);
		if (a) {
			if (c) {
				uf.unite(a, b);
				uf.unite(n + a, n + b);
			}
			else {
				uf.unite(a, n + b);
				uf.unite(n + a, b);
			}
		}
		else {
			if (c) uf.unite(0, b);
			else uf.unite(0, n + b);
		}
		_uf.unite(a, b);
	}
	for (int u = 1; u < n; u++)
		if (uf.same(u, n + u)) {
			cout << 0 << endl;
			return 0;
		}
	int ans = 1;
	for (int u = 1; u < n; u++)
		if (_uf.find(u) == u && !_uf.same(u, 0))
			ans = ans * 2 % MOD;
	cout << ans << endl;
}