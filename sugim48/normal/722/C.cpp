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
 
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define pb push_back
 
int INF = INT_MAX / 10;
ll MOD = 924844033;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct union_find {
	vector<int> v;
	vector<ll> w;
	union_find(int n) : v(n, -1), w(n) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
		w[x] += w[y];
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
	ll sum(int x) { return w[find(x)]; }
};

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<int> p(N);
	rep(i, N) scanf("%d", &p[i]), p[i]--;
	union_find uf(N * 2 - 1);
	rep(i, N) uf.w[i * 2] = a[i];
	ll ma = 0;
	vector<ll> ans(N);
	for (int k = N - 1; k >= 0; k--) {
		ans[k] = ma;
		int i = p[k];
		if (i > 0) uf.unite(i * 2, i * 2 - 1);
		if (i < N - 1) uf.unite(i * 2, i * 2 + 1);
		ma = max(ma, uf.sum(i * 2));
	}
	rep(k, N) printf("%lld\n", ans[k]);
}