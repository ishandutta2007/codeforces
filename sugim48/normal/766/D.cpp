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
#include <unordered_set>
#include <complex>
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
typedef complex<double> C;

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
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
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<string> a(N);
	rep(i, N) cin >> a[i];
	sort(a.begin(), a.end());
	union_find uf(N * 2);
	while (M--) {
		int q; scanf("%d", &q);
		string s, t; cin >> s >> t;
		int i = lower_bound(a.begin(), a.end(), s) - a.begin();
		int j = lower_bound(a.begin(), a.end(), t) - a.begin();
		if (q == 1) {
			if (uf.same(i, j + N)) printf("NO\n");
			else printf("YES\n"), uf.unite(i, j), uf.unite(i + N, j + N);
		}
		if (q == 2) {
			if (uf.same(i, j)) printf("NO\n");
			else printf("YES\n"), uf.unite(i, j + N), uf.unite(i + N, j);
		}
	}
	while (Q--) {
		string s, t; cin >> s >> t;
		int i = lower_bound(a.begin(), a.end(), s) - a.begin();
		int j = lower_bound(a.begin(), a.end(), t) - a.begin();
		if (uf.same(i, j)) printf("1\n");
		else if (uf.same(i, j + N)) printf("2\n");
		else printf("3\n");
	}
}