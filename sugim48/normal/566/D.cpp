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
	int n, q; cin >> n >> q;
	union_find uf(n);
	set<int> s;
	for (int x = 0; x < n; x++)
		s.insert(x);
	while (q--) {
		int t, x, y; scanf("%d%d%d", &t, &x, &y);
		x--; y--;
		if (t == 1) uf.unite(x, y);
		if (t == 2) {
			auto it = s.upper_bound(x);
			while (it != s.end() && *it <= y) {
				uf.unite(x, *it);
				s.erase(it++);
			}
		}
		if (t == 3) printf("%s\n", uf.same(x, y) ? "YES" : "NO");
	}
}