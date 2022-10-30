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

int n, k;
int r[100000], a[100000];
int lf[100000], rg[100000];
int best[100000];
int pos[100000];
vector <pair <int, pii> > A;
vector <pii> B, C;
int lst;
int tmax[262144];
int t[262144];
int ans[100000];
int m;
int LL[100000], RR[100000];

void update (int v, int x) {
	v += lst;
	t[v] += x;
	while (v > 1) {
		v >>= 1;
		t[v] = t[v*2] + t[v*2+1];
	}
}

int rmq (int v, int l, int r, int a, int b) {
	if (r < a || l > b)
		return 0;
	if (a <= l && r <= b)
		return t[v];
	int mid = (l + r) >> 1;
	return rmq (v*2, l, mid, a, b)+
	rmq (v*2+1, mid+1, r, a, b);
}

int rmaxq (int v, int l, int r, int a, int b) {
	if (r < a || l > b)
		return 0;
	if (a <= l && r <= b)
		return tmax[v];
	int mid = (l + r) >> 1;
	return max (rmaxq (v*2, l, mid, a, b),
	rmaxq (v*2+1, mid+1, r, a, b));
}

void updatemax (int v, int x) {
	v += lst;
	tmax[v] = x;
	while (v > 1) {
		v >>= 1;
		tmax[v] = max (tmax[v*2], tmax[v*2+1]);
	}
}

void calc (int i) {
	int x = rmaxq (1, 0, lst-1, LL[i], RR[i]);
	if (x < 2)
		x = -1;
	ans[i] = x;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> k;
	lst = 1;
	while (lst < n)
		lst *= 2;
	forn (i, n)
		scanf ("%d", &r[i]);
	forn (i, n)
		scanf ("%d", &a[i]);
	A.resize (n);
	forn (i, n)
		A[i] = mp (a[i], mp (r[i], i));
	sort (all (A));
	forn (i, n)
		pos[A[i].sc.sc] = i;
	forn (i, n) {
		a[i] = A[i].fs;
		r[i] = A[i].sc.fs;
	}
	B.resize (n);
	forn (i, n)
		B[i] = mp (r[i], i);
	sort (all (B));
	reverse (all (B));
	seta (t, 0);
	forn (i, n)
		t[i+lst] = 1;
	for (int i = lst-1; i >= 1; i --)
		t[i] = t[i*2] + t[i*2+1];
	int p = 0;
	seta (tmax, 0);
	forn (ii, n) {
		int v = ii;
		lf[v] = v;
		rg[v] = v;
		ford (i, 20) {
			if (rg[v] + (1<<i) < n && a[v] + k >= a[rg[v]+(1<<i)])
				rg[v] += 1 << i;
			if (lf[v] - (1<<i) >= 0 && a[v] - k <= a[lf[v]-(1<<i)])
				lf[v] -= 1 << i;
		}
	}
	cin >> m;
	forn (i, m) {
		int x, y;
		scanf ("%d%d", &x, &y);
		x = pos[x-1];
		y = pos[y-1];
		int L = max (lf[x], lf[y]);
		int R = min (rg[x], rg[y]);
		LL[i] = L;
		RR[i] = R;
		C.pb (mp (max (r[x], r[y]), i));
	}
	sort (all (C));
	reverse (all (C));
	int pc = 0;
	forn (i, n) {
		while (B[p].fs > B[i].fs) {
			update (B[p].sc, -1);
			p ++;
		}
		while (pc < I C.size() && C[pc].fs > B[i].fs) {
			calc (C[pc].sc);
			pc ++;
		}
		int v = B[i].sc;	
		best[v] = rmq (1, 0, lst-1, lf[v], rg[v]);
		updatemax (v, best[v]);
	}
	while (pc < I C.size()) {
		calc (C[pc].sc);
		pc ++;
	}
	forn (i, m)
		printf ("%d\n", ans[i]);
	return 0;
}