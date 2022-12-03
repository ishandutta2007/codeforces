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

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct segment_tree {
	int n; vector<char> v;
	segment_tree(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<char>(n * 2 - 1, ' ');
	}
	char get(int i) {
		int k = i + n - 1;
		char c = v[k];
		while (k > 0) {
			k = (k - 1) / 2;
			if (v[k] != ' ') c = v[k];
		}
		return c;
	}
	void _set(int i, int j, char c, int k, int l, int r) {
		if (r <= i || j <= l) return;
		if (i <= l && r <= j) {
			v[k] = c;
			return;
		}
		if (v[k] != ' ') {
			v[k * 2 + 1] = v[k];
			v[k * 2 + 2] = v[k];
			v[k] = ' ';
		}
		_set(i, j, c, k * 2 + 1, l, (l + r) / 2);
		_set(i, j, c, k * 2 + 2, (l + r) / 2, r);
	}
	void set(int i, int j, char c) { return _set(i, j, c, 0, 0, n); }
};

set<int> st[10][10];
char p[20];

int main() {
	int n, m, k; cin >> n >> m >> k;
	string s; cin >> s;
	segment_tree tree(n);
	for (int i = 0; i < n; i++)
		tree.v[i + tree.n - 1] = s[i];
	for (int i = 0; i + 1 < n; i++) {
		int c = s[i] - 'a', d = s[i + 1] - 'a';
		st[c][d].insert(i + 1);
	}
	while (m--) {
		int q; scanf("%d", &q);
		if (q == 1) {
			int l, r;
			char c;
			scanf("%d%d%*c%c", &l, &r, &c);
			l--;
			tree.set(l, r, c);
			c -= 'a';
			for (int d = 0; d < k; d++)
				for (int e = 0; e < k; e++) {
					set<int>& unko = st[d][e];
					for (auto it = unko.lower_bound(l); it != unko.end() && *it <= r;)
						unko.erase(*(it++));
				}
			if (l - 1 >= 0) {
				char d = tree.get(l - 1) - 'a';
				if (d != c) st[d][c].insert(l);
			}
			if (r < n) {
				char d = tree.get(r) - 'a';
				if (d != c) st[c][d].insert(r);
			}
		}
		if (q == 2) {
			scanf("%s", p);
			int ans = n;
			for (int i = 0; i < k; i++)
				for (int j = i + 1; j < k; j++) {
					char c = p[i] - 'a', d = p[j] - 'a';
					ans -= st[c][d].size();
				}
			printf("%d\n", ans);
		}
		
	}
}