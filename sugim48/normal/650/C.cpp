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
#include <unordered_map>
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
	int N, M; cin >> N >> M;
	vector<vector<int> > a(N, vector<int>(M));
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			scanf("%d", &a[y][x]);
	vector<int> A;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			A.push_back(a[y][x]);
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	int n = A.size();
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			a[y][x] = lower_bound(A.begin(), A.end(), a[y][x]) - A.begin();
	vector<vector<i_i> > mp(n);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			mp[a[y][x]].push_back(i_i(y, x));
	vector<int> r(N), c(M);
	vector<vector<int> > ans(N, vector<int>(M));
	for (int z = 0; z < n; z++) {
		vector<i_i> v = mp[z];
		int n = v.size();
		unordered_map<int, vector<int> > Y, X;
		for (int i = 0; i < n; i++) {
			int y = v[i].first, x = v[i].second;
			Y[y].push_back(i);
			X[x].push_back(i);
		}
		union_find uf(n);
		for (auto it = Y.begin(); it != Y.end(); it++) {
			vector<int> v = it->second;
			for (int i = 0; i + 1 < v.size(); i++)
				uf.unite(v[i], v[i + 1]);
		}
		for (auto it = X.begin(); it != X.end(); it++) {
			vector<int> v = it->second;
			for (int i = 0; i + 1 < v.size(); i++)
				uf.unite(v[i], v[i + 1]);
		}
		vector<int> ma(n);
		for (int i = 0; i < v.size(); i++) {
			int y = v[i].first, x = v[i].second;
			int p = uf.find(i);
			ma[p] = max(ma[p], max(r[y], c[x]) + 1);
		}
		for (int i = 0; i < v.size(); i++) {
			int y = v[i].first, x = v[i].second;
			int p = uf.find(i);
			ans[y][x] = ma[p];
			r[y] = max(r[y], ans[y][x]);
			c[x] = max(c[x], ans[y][x]);
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++)
			printf("%d ", ans[y][x]);
		cout << endl;
	}
}