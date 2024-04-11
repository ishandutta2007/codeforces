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
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

struct rec {
	int l, r;
	rec () {l = r = 0;}
	rec (int l1, int r1) {
		l = l1;
		r = r1;
	}
};

struct state {
	state *vl;
	state *vr;
	int l, r;
	int s;
};

bool operator < (rec p1, rec p2) {
	if (p1.r - p1.l != p2.r - p2.l)
		return (p1.r - p1.l < p2.r - p2.l);
	else
		return p1.r < p2.r;
}

set <int> S;
set <rec> Q;
map <int, int> M;
state t[5000000], *r;
int list, tlist;

state * newstate (int l, int r) {
	list ++;
	t[list].vl = t[list].vr = 0;
	t[list].s = 0;
	t[list].l = l;
	t[list].r = r;
	return &t[list];	
}

int sum (state *v) {
	if (v == 0)
		return 0;
	return v->s;
}

int rmq (state *v, int l, int r) {
	if (v == NULL)
		return 0;
	if (l <= v->l && v->r <= r)
		return v->s;
	if (v->r < l || r < v->l)
		return 0;
	return rmq (v->vl, l, r) + rmq (v->vr, l, r);
}

void update (state *v, int p, int c) {
	if (v->l == p && v->r == p) {
		v->s = c;
		return;
	}
	int m = (v->l + v->r) / 2;
	if (v->l <= p && p <= m) {
		if (v->vl == 0) 
			v->vl = newstate (v->l, m);
	        update (v->vl, p, c);
	} else {
		if (v->vr == 0) 
			v->vr = newstate (m+1, v->r);
	        update (v->vr, p, c);
	}
	v->s = sum (v->vl) + sum (v->vr);
}


int main ()
{
	list = -1;
	int n, q;
	scanf ("%d%d", &n, &q);
	S.clear ();
	S.insert (0);
	S.insert (n+1);
	Q.insert (rec (1, n));
	M.clear ();
	tlist = 1;
	while (tlist < n)
		tlist *= 2;
	r = newstate (1, tlist);
	forn (i, q) {
		int x;
		scanf ("%d", &x);
		if (x > 0) {
			if (M.count (x)) {
				int y = M[x];
				update (r, y, 0);
				M.erase (x);
				int l1 = y+1;
				set <int> :: iterator it = S.find (y);
				it ++;
				int r1 = (*it) - 1;
				it --;
				it --;
				int r2 = y-1;
				int l2 = (*it) + 1;
				S.erase (y);
				if (l1 <= r1)
					Q.erase (rec (l1, r1));
				if (l2 <= r2)
					Q.erase (rec (l2, r2));
				Q.insert (rec (l2, r1));
			} else {
				rec tmp = *Q.rbegin();
				Q.erase (tmp);
				int y = (tmp.r + tmp.l + 1)  / 2;
				update (r, y, 1);
				M[x] = y;
				S.insert (y);
				int l1 = tmp.l;
				int r1 = y - 1;
				int l2 = y + 1;
				int r2 = tmp.r;
				if (l1 <= r1)
					Q.insert (rec (l1, r1));
				if (l2 <= r2)
					Q.insert (rec (l2, r2));
			}
		} else {
			int l, r1;
			scanf ("%d%d", &l, &r1);
			printf ("%d\n", rmq (r, l, r1));	
		}
	}
	return 0;
}