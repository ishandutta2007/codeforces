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

#define rep(i, N) for (int i = 0; i < N; i++)

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

vector<int> bfs(int N, vector<vector<int> >& G, int s) {
	vector<int> d(N, INT_MAX / 2); d[s] = 0;
	queue<int> q; q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v: G[u])
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
	return d;
}

int main() {
	int N; cin >> N;
	vector<int> c(N);
	rep(u, N) scanf("%d", &c[u]);
	vector<int> a(N - 1), b(N - 1);
	rep(i, N - 1) scanf("%d%d", &a[i], &b[i]), a[i]--, b[i]--;
	union_find uf(N);
	rep(i, N - 1) if (c[a[i]] == c[b[i]]) uf.unite(a[i], b[i]);
	int n = 0;
	vector<int> unko(N, -1);
	rep(u, N) if (uf.root(u)) unko[u] = n++;
	vector<vector<int> > G(n);
	rep(i, N - 1) if (c[a[i]] != c[b[i]]) {
		int u = unko[uf.find(a[i])], v = unko[uf.find(b[i])];
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<int> d0 = bfs(n, G, 0);
	int x = 0;
	rep(u, n) if (d0[u] > d0[x]) x = u;
	vector<int> dx = bfs(n, G, x);
	int y = 0;
	rep(u, n) if (dx[u] > dx[y]) y = u;
	cout << (dx[y] + 1) / 2 << endl;
}