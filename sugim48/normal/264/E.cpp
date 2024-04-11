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

ll INF = LLONG_MAX / 3;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct unko {
	int l, r, ma = 0;
	unko *lch, *rch;
	unko(int l, int r) : l(l), r(r) {
		if (r - l == 1) return;
		lch = new unko(l, (l + r) / 2);
		rch = new unko((l + r) / 2, r);
	}
	int get(int i, int j) {
		if (j <= l || r <= i) return 0;
		if (i <= l && r <= j) return ma;
		return max(lch->get(i, j), rch->get(i, j));
	}
	void set(int i, int x) {
		if (i < l || r <= i) return;
		if (r - l == 1) {
			ma = x;
			return;
		}
		lch->set(i, x);
		rch->set(i, x);
		ma = max(lch->ma, rch->ma);
	}
};

int main() {
	int N, Q; cin >> N >> Q;
	set<int> st;
	vector<int> q;
	vector<int> a(N, -1);
	unko* z = new unko(0, Q + 100);
	unko* Z = new unko(0, N);
	while (Q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int i, h; scanf("%d%d", &i, &h);
			i--;
			st.insert(i);
			q.push_back(i);
			if (q.size() > 10) q.erase(q.begin());
			a[i] = Q + h;
			vector<i_i> p;
			for (int i: q)
				if (a[i] <= Q + h && a[i] != -1) {
					p.push_back(i_i(a[i], i));
					Z->set(i, 0);
				}
			sort(p.begin(), p.end());
			reverse(p.begin(), p.end());
			for (i_i ai: p) {
				int i = ai.second;
				int x = Z->get(i + 1, N) + 1;
				z->set(a[i], x);
				Z->set(i, x);
			}
			printf("%d\n", z->ma);
		}
		if (t == 2) {
			int k; scanf("%d", &k);
			k--;
			auto it = st.begin();
			while (k--) {
				int i = *it;
				z->set(a[i], 0);
				it++;
			}
			int i = *it;
			it = st.erase(it);
			z->set(a[i], 0);
			Z->set(i, 0);
			a[i] = -1;
			while (it != st.begin()) {
				it--;
				int i = *it;
				int x = z->get(a[i] + 1, z->r) + 1;
				z->set(a[i], x);
				Z->set(i, x);
			}
			printf("%d\n", z->ma);
		}
	}
}