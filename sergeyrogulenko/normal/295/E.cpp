#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

map<int, int> num;
int n, m;
set<int> X;
map<int, int> mx;
int x[100500];
int x1[100500];
int tp[100500], c1[100500], c2[100500];
int tt[800500];
int64 tsum[800500];
int64 sum[800500];
int64 tpush[800500];
int lst;
int xx[200500];

void ttupdate(int v, int value) {
	v = v + lst;
	tt[v] = value;
	while (v > 1) {
		v >>= 1;
		tt[v] = tt[v*2] + tt[v*2+1];		
	}
}

void tsumupdate(int v, int64 value, int64 vvalue) {
	v = v + lst;
	int64 add = value - tsum[v];
	tsum[v] = value;
	sum[v] = vvalue;
	while (v > 1) {
		v >>= 1;
		sum[v] = sum[v*2] + sum[v*2+1];
		tsum[v] += add;
	}
}

void push(int v) {
	tsum[v] += tpush[v] * sum[v];
	if (v < lst) {
		tpush[v*2] += tpush[v];
		tpush[v*2+1] += tpush[v];
	}
	tpush[v] = 0;
}

void tsumadd(int v, int l, int r, int a, int b, int64 cnt) {
	push(v);
	if (r < a || l > b) return;
	if (a <= l && r <= b) {
		tpush[v] += cnt;
		return;
	}
	int mid = (l + r) / 2;
	tsumadd(v*2, l, mid, a, b, cnt);
	tsumadd(v*2+1, mid+1, r, a, b, cnt);
	tsum[v] = tsum[v*2] + tsum[v*2+1];
}

int ttget(int v, int l, int r, int a, int b) {
	if (r < a || l > b) return 0;
	if (a <= l && r <= b)
		return tt[v];
	int mid = (l + r) / 2;
	return ttget(v*2, l, mid, a, b) + ttget(v*2+1, mid+1, r, a, b);
}

void add(int x) {
	int pos = mx[x];
	tsumadd(1, 0, lst-1, pos+1, lst-1, 1);
	ttupdate(pos, 1);
	int ind = ttget(1, 0, lst-1, 0, pos);
	tsumadd(1, 0, lst-1, pos, pos, 0);
	tsumupdate(pos, 2LL * x * (int64)ind, 2LL * x);
}

void del(int x) {
	int pos = mx[x];
	tsumadd(1, 0, lst-1, pos+1, lst-1, -1);
	ttupdate(pos, 0);
	tsumadd(1, 0, lst-1, pos, pos, 0);
	tsumupdate(pos, 0, 0);
}

pair<int64, int64> get_sum_ts(int v, int l, int r, int a, int b) {
	push(v);
	if (r < a || l > b) return mp(0LL, 0LL);
	if (a <= l && r <= b) return mp(tsum[v], sum[v]);
	int mid = (l + r) / 2;
	pair<int64, int64> p1, p2;
	p1 = get_sum_ts(v*2, l, mid, a, b);
	p2 = get_sum_ts(v*2+1, mid+1, r, a, b);
	tsum[v] = tsum[v*2] + tsum[v*2+1];
	return mp(p1.fs + p2.fs, p1.sc + p2.sc);
}

int64 get(int l, int r) {
	set<int> :: iterator il = X.lower_bound(l);
	set<int> :: iterator ir = X.lower_bound(r+1);
	if (il == X.end()) return 0;
	if (ir == X.begin()) return 0;
	ir--;
	int pl = mx[*il];
	int pr = mx[*ir];
	if (pl > pr) return 0;
	pair<int64, int64> res = get_sum_ts(1, 0, lst-1, pl, pr);
	pl = ttget(1, 0, lst-1, 0, pl-1) + 1;
	pr = ttget(1, 0, lst-1, 0, pr);
	return res.fs - res.sc / 2 * (pr + pl);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	forn(i, n)
		scanf("%d", &x[i]);
	cin >> m;
	forn(i, n)
		x1[i] = x[i];
	X.clear();
	forn(i, n)
		X.insert(x1[i]);
	forn(i, m) {
		scanf("%d%d%d", &tp[i], &c1[i], &c2[i]);
		if (tp[i] == 1) {
			c1[i]--;
			x1[c1[i]] += c2[i];
			X.insert(x1[c1[i]]);			
		}
	}
	int pos = 0;
	for(set<int> :: iterator it = X.begin(); it != X.end(); it++) {
		mx[*it] = pos;
		xx[pos] = *it;
		pos++;
	}
	seta(tt, 0);
	seta(sum, 0);
	seta(tsum, 0);
	lst = 1;
	while (lst < I X.size() + 1)
		lst *= 2;
	forn(i, n)
		add(x[i]);
	forn(i, m) {
		if (tp[i] == 1) {
			int v = c1[i];
			del(x[v]);
			x[v] += c2[i];
			add(x[v]);
		} else {
			int l = c1[i];
			int r = c2[i];
			printf("%I64d\n", get(l, r));
		}
	}
	return 0;
}