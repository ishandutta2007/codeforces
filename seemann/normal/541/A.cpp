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
#include <cassert>

using namespace std;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
	
typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const int MAXN = 2e5 + 10;

struct tree {
	int x[4 * MAXN];
	int sz;

	void build(int n) {
		sz = 1;
		while (sz < n)
			sz *= 2;

		forab(i, 1, 2 * sz)
			x[i] = 0;
	}

	void set(int p, int val) {
		int j = sz + p;
		x[j] = val;

		while (j > 1) {
			j /= 2;
			x[j] = max(x[2 * j], x[2 * j + 1]);
		}
	}

	int getMax(int l, int r, int v=1, int L=0, int R=-1) {
		if (R == -1)
			R = sz;

		if (R <= l || r <= L)
			return -INF;

		if (l <= L && R <= r)
			return x[v];

		return max(getMax(l, r, 2 * v, L, (L + R) / 2), getMax(l, r, 2 * v + 1, (L + R) / 2, R));
	}
};

struct seg {
	int l, r;
	int c;
	int num;
};

int n, m;
seg rl[MAXN];
seg rl2[MAXN];

seg ch[MAXN];

bool lessl(const seg & a, const seg & b) {
	return a.l < b.l;
}

bool lessr(const seg & a, const seg & b) {
	return a.r < b.r;
}

bool lessnum(const seg & a, const seg & b) {
	return a.num < b.num;
}

ll ans = 0;
int chnum, rlnum;

tree t;

int main() {
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	
	forn(i, n) {
		scanf("%d%d", &rl[i].l, &rl[i].r);
		rl[i].num = i;
	}
	forn(i, m) {
		scanf("%d%d%d", &ch[i].l, &ch[i].r, &ch[i].c);
		ch[i].num = i;
	}

	forn(q, 2) {
		forn(i, n) {
			rl[i].l *= -1;
			rl[i].r *= -1;
			swap(rl[i].l, rl[i].r);
		}
		forn(i, m) {
			ch[i].l *= -1;
			ch[i].r *= -1;
			swap(ch[i].l, ch[i].r);
		}
		sort(rl, rl + n, lessl);
		sort(ch, ch + m, lessr);


		t.build(n);
		forn(i, n)
			t.set(i, rl[i].r);

		forn(i, m) {
			int pos = lower_bound(rl, rl + n, ch[i], lessl) - rl;

			int r = t.getMax(0, pos);
			if (r > ch[i].l) {
				ll cur = (min(r, ch[i].r) - ch[i].l) * 1ll * ch[i].c;

				if (ans < cur) {
					ans = cur;
					chnum = ch[i].num;
				}
			}
		}
	}

	forn(i, n) {
		rl2[i] = rl[i];
		rl2[i].num = i;
	}
	sort(rl2, rl2 + n, lessr);

	t.build(n);
	int k = 0;
	forn(i, m) {
		while (k < n && rl2[k].r <= ch[i].r) {
			t.set(rl2[k].num, rl2[k].r - rl2[k].l);
			k++;
		}

		int pos = lower_bound(rl, rl + n, ch[i], lessl) - rl;

		int len = t.getMax(pos, t.sz);

		if (len * 1ll * ch[i].c > ans) {
			ans = len * 1ll * ch[i].c;
			chnum = ch[i].num;
		}
	}

	cout << ans << '\n';

	if (ans > 0) {

		sort(rl, rl + n, lessnum);
		sort(ch, ch + m, lessnum);

		rlnum = -1;

		forn(i, n) {
			ll cur = ch[chnum].c * 1ll * (min(ch[chnum].r, rl[i].r) - max(ch[chnum].l, rl[i].l));

			if (cur == ans) {
				rlnum = i;
				break;
			}
		}

		assert(rlnum != -1);

		printf("%d %d\n", rlnum + 1, chnum + 1);
	}

	return 0;
}