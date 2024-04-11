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

typedef long long int64;
typedef pair <int, int> pii;
typedef pair <int64, int64> pii64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

const int blocksize = 250;

struct block {
	int l, r;
	int size;
	int64 next_time;
	int pmax;
};

int n, k, m;
pii64 A[100000];
block blocks[500];
int ans[100000];
int L[100000], R[100000], T[100000];
vector <pii> Q;

bool myless (pii64 a, pii64 b, int64 tm) {
	return a.fs + tm * a.sc < b.fs + tm * b.sc;
}

void process (int v, int64 tm) {
	int best = blocks[v].l;
	for (int i = blocks[v].l; i <= blocks[v].r; i ++)
		if (myless (A[best], A[i], tm))
			best = i;
	blocks[v].pmax = best;
	blocks[v].next_time = inf;
	pii64 cur = A[best];
	for (int i = blocks[v].l; i <= blocks[v].r; i ++) {
		pii64 tmp = A[i];
		if (cur.sc < tmp.sc)
			blocks[v].next_time = min (blocks[v].next_time, (cur.fs - tmp.fs) / (tmp.sc - cur.sc) + 1);
	}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &k);
	forn (i, n) {
		int x, y;
		scanf ("%d %d", &x, &y);
		A[i] = mp ((int64)x, (int64)y);
	}
	Q.resize (k);
	forn (i, k) {
		scanf ("%d%d%d", &L[i], &R[i], &T[i]);
		L[i] --;
		R[i] --;
		Q[i] = mp (T[i], i);
	}
	sort (all (Q));
	int l = 0;
	int m = 0;
	while (l < n) {
		int r = min (l + blocksize - 1, n-1);
		blocks[m].l = l;
		blocks[m].r = r;
		blocks[m].size = r - l + 1;
		l = r + 1;
		m ++;
	}
	forn (i, m) {
		blocks[i].pmax = blocks[i].l;
		blocks[i].next_time = -1;
	}
	forn (i, k) {
		int num = Q[i].sc;
		int best = L[num];
		int r1 = R[num];
		int l1 = L[num];
		forn (j, m) {
			if (T[num] >= blocks[j].next_time)
				process (j, T[num]);
			if (L[num] <= blocks[j].l && blocks[j].r <= R[num]) {
				if (myless (A[best], A[blocks[j].pmax], T[num]))
					best = blocks[j].pmax;
				r1 = min (r1, blocks[j].l - 1);
				l1 = max (l1, blocks[j].r + 1);
			}
		}
		l1 = max (l1, r1 + 1);
		for (int j = L[num]; j <= r1; j ++)
			if (myless (A[best], A[j], T[num]))
				best = j;
		for (int j = l1; j <= R[num]; j ++)
			if (myless (A[best], A[j], T[num]))
				best = j;
		ans[num] = best;
	}
	forn (i, k)
		printf ("%d\n", ans[i]+1);
	return 0;
}