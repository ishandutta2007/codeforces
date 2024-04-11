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
typedef pair<int, ll> i_ll;
struct edge { int u, v; ll w; };

double INF = DBL_MAX / 10;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int f(int N, int n, vector<pair<i_i, char> >& unko) {
	union_find uf((n + 1) * 2);
	for (auto yxc: unko) {
		int y = yxc.first.first, x = yxc.first.second;
		char c = yxc.second;
		int z1 = x - y, z2 = x + y;
		if (z1 < 0) z1 = -z1;
		if (z2 >= N) z2 = N * 2 - 2 - z2;
		z1 /= 2; z2 /= 2;
		z2++;
		if (c == 'x') {
			uf.unite(z1, z2);
			uf.unite(n+1 + z1, n+1 + z2);
		}
		if (c == 'o') {
			uf.unite(n+1 + z1, z2);
			uf.unite(z1, n+1 + z2);
		}
	}
	for (int z = 0; z <= n; z++)
		if (uf.same(z, n+1 + z))
			return 0;
	int ans = MOD / 2 + 1;
	for (int z = 0; z <= n; z++)
		if (uf.root(z))
			ans = ans * 2 % MOD;
	return ans;
}

int main() {
	int N, M; cin >> N >> M;
	vector<pair<i_i, char> > unko1, unko2;
	while (M--) {
		int y, x, c; scanf("%d %d %c", &y, &x, &c);
		y--; x--;
		pair<i_i, char> yxc(i_i(y, x), c);
		if ((y + x) % 2 == 0) unko1.push_back(yxc);
		else unko2.push_back(yxc);
	}
	int ans1 = f(N, (N + 1) / 2, unko1);
	int ans2 = f(N, N / 2, unko2);
	cout << (ll)ans1 * ans2 % MOD << endl;
}