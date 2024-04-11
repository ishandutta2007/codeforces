#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

int nxt() {
	int x; scanf("%d", &x);
	return x;
}

const int N = 1000500;
int a[N], t[N], x[N];
int sz;
int ans[N];

pii tmp[N];
int tree[N];

int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += tree[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i < sz; i = (i | (i+1)))
		tree[i] += delta;
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n = nxt();
    vpi els(n);
    forn (i, n) {
		a[i] = nxt(), t[i] = nxt(), x[i] = nxt();
		els[i] = mp(x[i], i);
	}
	sort(all(els));
	for (size_t i = 0; i < els.size(); ) {
		auto ni = i;
		int st = 0;
		while (ni < els.size() && els[ni].fi == els[i].fi) {
			tmp[st++] = mp(t[els[ni].se], els[ni].se);
			ni++;
		}
		sort(tmp, tmp + st);
		forn (l, st)
			t[tmp[l].se] = l;
		sz = st;
		forn (i, sz) tree[i] = 0;
		
		for (size_t j = i; j < ni; j++) {
			int ind = els[j].se;
			int ct = t[ind];
			assert(ct >= 0 && ct < sz);
			if (a[ind] == 1) {
				inc(ct, 1);
			}
			if (a[ind] == 2) {
				inc(ct, -1);
			}
			if (a[ind] == 3)
				ans[ind] = sum(ct);
		}
		i = ni;
	}
	forn (i, n)
		if (a[i] == 3) {
			printf("%d\n", ans[i]);
			assert(ans[i] >= 0);
		}
    return 0;
}