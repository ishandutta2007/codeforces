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

int main() {
	int N, M; cin >> N >> M;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<vector<int> > G(N);
	rep(j, M) {
		int K; scanf("%d", &K);
		while (K--) {
			int i; scanf("%d", &i); i--;
			G[i].pb(j);
		}
	}
	union_find uf(M * 2);
	rep(i, N) {
		int j1 = G[i][0], j2 = G[i][1];
		if (a[i]) uf.unite(j1, j2), uf.unite(M + j1, M + j2);
		else uf.unite(j1, M + j2), uf.unite(M + j1, j2);
	}
	rep(j, M) if (uf.same(j, M + j)) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
}