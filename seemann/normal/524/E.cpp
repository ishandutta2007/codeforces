#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <complex>

using namespace std;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
	
typedef long long ll;
typedef long double ldb;

const int MAXN = 200010;
const int INF = 1e9;

struct tree {
	int x[4 * MAXN];
	int sz;

	void build(int n) {
		sz = 1;
		while (sz < n)
			sz *= 2;

		forab(i, 1, 2 * sz)
			x[i] = -1;
	}

	void set(int val, int pos) {
		int i = sz + pos;
		x[i] = val;
		i /= 2;
		while (i > 0) {
			x[i] = min(x[2 * i], x[2 * i + 1]);
			i /= 2;
		}
	}

	int get_min(int l, int r, int v=1, int L=0, int R=-1) {
		if (R == -1)
			R = sz;

		if (r <= L || R <= l)
			return INF;

		if (l <= L && R <= r)
			return x[v];

		return min(get_min(l, r, 2 * v, L, (L + R) / 2), get_min(l, r, 2 * v + 1, (L + R) / 2, R));
	}
};

int n[2];
int k, q;

int x[2][MAXN];

bool ans[MAXN];
int d[2][2][MAXN];

struct event {
	int t;
	int x;
	int num;

	event(): t(), x(), num() {}
	event(int t, int x, int num): t(t), x(x), num(num) {}

	bool operator <(const event & e) const {
		if (x != e.x)
			return x < e.x;

		if (t != e.t)
			return t < e.t;

		return num < e.num;
	}
};

vector<event> e[2];
tree t;

int main() {
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d%d%d", &n[0], &n[1], &k, &q);

	forn(i, k) {
		forn(z, 2) {
			scanf("%d", &x[z][i]);
			x[z][i]--;
		}
		forn(z, 2)
			e[z].push_back(event(0, x[z][i], i));
	}

	forn(i, q) {
		scanf("%d%d%d%d", &d[0][0][i], &d[1][0][i], &d[0][1][i], &d[1][1][i]);
		forn(a, 2)
			forn(b, 2)
				d[a][b][i]--;

		forn(z, 2) {
			e[z].push_back(event(1, d[z][1][i], i));
		}

		ans[i] = false;
	}

	forn(z, 2) {
		t.build(n[1 - z] + 100);

		sort(e[z].begin(), e[z].end());

		forn(i, e[z].size()) {
			event cur = e[z][i];

			if (cur.t == 0) {
				t.set(cur.x, x[1 - z][cur.num]);
			} else {
				if (t.get_min(d[1 - z][0][cur.num], d[1 - z][1][cur.num] + 1) >= d[z][0][cur.num])
					ans[cur.num] = true;
			}
		}
	}

	forn(i, q)
		printf(ans[i] ? "YES\n" : "NO\n");


	return 0;
}