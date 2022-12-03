#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
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
	int n; cin >> n;
	vector< vector<int> > d(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &d[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if ((i == j && d[i][j] > 0) || (i != j && d[i][j] == 0)) {
				cout << "NO" << endl;
				return 0;
			}
		}
	vector<i_i> a;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (d[i][j] != d[j][i]) {
				cout << "NO" << endl;
				return 0;
			}
			else a.push_back(i_i(d[i][j], i * n + j));
	sort(a.begin(), a.end());
	union_find uf(n);
	vector< vector<int> > v(n);
	for (int i = 0; i < n; i++) v[i].push_back(i);
	vector< vector<ll> > e(n, vector<ll>(n));
	for (int k = 0; k < a.size(); k++) {
		int i = a[k].second / n, j = a[k].second % n;
		ll d = a[k].first;
		if (uf.same(i, j)) {
			if (e[i][j] != d) {
				cout << "NO" << endl;
				return 0;
			}
		}
		else {
			int x = uf.find(i), y = uf.find(j);
			for (int _i = 0; _i < v[x].size(); _i++) {
				for (int _j = 0; _j < v[y].size(); _j++) {
					int s = v[x][_i], t = v[y][_j];
					e[s][t] = e[t][s] = d + e[i][s] + e[j][t];
				}
			}
			uf.unite(i, j);
			int z = uf.find(i);
			vector<int> _v;
			for (int _i = 0; _i < v[x].size(); _i++)
				_v.push_back(v[x][_i]);
			for (int _j = 0; _j < v[y].size(); _j++)
				_v.push_back(v[y][_j]);
			v[z] = _v;
		}
	}
	cout << "YES" << endl;
}