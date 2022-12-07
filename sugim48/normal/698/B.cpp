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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int INF = INT_MAX / 2;
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

int u0, sz;

void dfs(int u, vector<int>& a, vector<int>& unko) {
	int v = a[u];
	if (unko[v] == -1) {
		unko[v] = unko[u] + 1;
		dfs(v, a, unko);
	}
	else {
		u0 = v;
		sz = unko[u] + 1 - unko[v];
	}
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int& x: a) {
		scanf("%d", &x);
		x--;
	}
	union_find uf(N);
	for (int u = 0; u < N; u++)
		uf.unite(u, a[u]);
	vector<int> unko(N, -1);
	vector<i_i> p;
	for (int u = 0; u < N; u++)
		if (uf.root(u)) {
			unko[u] = 0;
			dfs(u, a, unko);
			p.push_back(i_i(sz, u0));
		}
	sort(p.begin(), p.end());
	int r = p[0].second, M = 0;
	for (i_i q: p) {
		int u = q.second, sz = q.first;
		if (u != r || sz >= 2) {
			M++;
			a[u] = r;
		}
	}
	cout << M << endl;
	for (int x: a) printf("%d ", x + 1);
	cout << endl;
}