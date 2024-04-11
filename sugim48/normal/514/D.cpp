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
struct edge { int u, v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

struct segment_tree_max {
	int n; vector<int> v;
	segment_tree_max(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<int>(n * 2 - 1, 0);
	}
	void set(int i, int x) {
		int k = i + n - 1;
		v[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = max(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	int _get(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return 0;
		if (i <= l && r <= j) return v[k];
		int vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		int vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	int get(int i, int j) { return _get(i, j, 0, 0, n); }
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<segment_tree_max> st(m, segment_tree_max(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int a; scanf("%d", &a);
			st[j].set(i, a);
		}
	int maxi = 0; vector<int> b(m);
	int r = 0;
	for (int l = 0; l <= n; l++) {
		for (;;) {
			if (r + 1 > n) break;
			int sum = 0;
			for (int j = 0; j < m; j++)
				sum += st[j].get(l, r + 1);
			if (sum > k) break;
			r++;
		}
		if (r - l > maxi) {
			maxi = r - l;
			for (int j = 0; j < m; j++)
				b[j] = st[j].get(l, r);
		}
	}
	for (int j = 0; j < m; j++)
		cout << b[j] << ' ';
	cout << endl;
}