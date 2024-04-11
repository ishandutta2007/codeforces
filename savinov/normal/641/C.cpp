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
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 2000500;
int x[N], t[N];

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n = nxt(), q = nxt();
    forn (i, q) {
		t[i] = nxt();
		if (t[i] == 1) x[i] = nxt();
	}
	vi ans(n);
	vi ss;
	forn (y, 2) {
		int u = y;
		forn (i, q)
			if (t[i] == 1)
			{
				u += x[i];
				if (u < 0) u += n;
				if (u >= n) u -= n;
			}
			else
				u ^= 1;
		ss.pb(u);
	}
	forn (j, 2)
	for (int i = 1 + j, v = ss[j]; i <= n; i += 2) {
		ans[v] = i;
		v += 2;
		if (v >= n) v -= n;
	}
	forn (i, n) printf("%d ", ans[i]);
    return 0;
}