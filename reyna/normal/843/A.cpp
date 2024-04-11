// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int par[N], a[N], b[N];
vector<int> s[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
int unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return 0;
	par[u] = v;
	return 1;
}
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		b[j] = a[j];
		par[j] = j;
	}
	sort(b, b + n);
	int comps = n;
	for (int j = 0; j < n; ++j) {
		int i = lower_bound(b, b + n, a[j]) - b;
		comps -= unite(i, j);
	}
	for (int j = 0; j < n; ++j)
		s[find(j)].push_back(j);
	cout << comps << '\n';
	for (int j = 0; j < n; ++j) if ((int) s[j].size()) {
		cout << (int) s[j].size() << ' ';
		for (int x : s[j]) cout << x + 1 << ' ';
		cout << '\n';
	}
	
		
}