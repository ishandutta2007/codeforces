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
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	union_find uf(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				uf.unite(i, j);
	}
	vector< vector<int> > v(n);
	for (int i = 0; i < n; i++)
		v[uf.find(i)].push_back(i);
	for (int i = 0; i < n; i++) {
		if (v[i].empty()) continue;
		vector<int> b;
		for (int j = 0; j < v[i].size(); j++)
			b.push_back(a[v[i][j]]);
		sort(b.begin(), b.end());
		for (int j = 0; j < v[i].size(); j++)
			a[v[i][j]] = b[j];
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}