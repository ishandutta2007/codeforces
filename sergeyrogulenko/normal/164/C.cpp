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

struct rec {
	int v, w, c, f, next, num;
};

int n, k, S, T;
int s[1000], t[1000], c[1000], lst;
vector <int> A;
map <int, int> MA;
int ver[10000], p[10000], d[10000], pr[10000];
rec reb[100000];

void _push (int v1, int v2, int c, int w, int num) {
	lst ++;
	reb[lst].v = v2;
	reb[lst].c = c;
	reb[lst].w = w;
	reb[lst].f = 0;
	reb[lst].next = ver[v1];
	reb[lst].num = num;
	ver[v1] = lst;
}

void push (int v1, int v2, int c, int w, int num) {
	_push (v1, v2, c, w, num);
	_push (v2, v1, 0, -w, -1);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
        cin >> n >> k;
        seta (ver, 255);
        lst = -1;
        forn (i, n)
        	cin >> s[i] >> t[i] >> c[i];
	forn (i, n) {
		t[i] += s[i];
		A.pb (s[i]);
		A.pb (t[i]);
	}
	sort (all (A));
	A.resize (unique (all (A)) - A.begin());
	forn (i, A.size())
		MA[A[i]] = i;
	forn (i, n) {
		s[i] = MA[s[i]];
		t[i] = MA[t[i]];
	}
	lst = -1;
	S = 0;
	T = A.size()-1;
	int N = T + 1;
	for (int i = S; i < T; i ++)
		push (i, i+1, k, 0, -1);
	forn (i, n)
		push (s[i], t[i], 1, c[i], i);
	forn (it, k) {
		forn (i, N)
			d[i] = -inf;
		d[0] = 0;
		seta (p, 255);
		forn (jt, N)
			forn (v, N)
				for (int ptr = ver[v]; ptr != -1; ptr = reb[ptr].next)
					if (reb[ptr].c > reb[ptr].f)
						if (d[reb[ptr].v] < d[v] + reb[ptr].w) {
							d[reb[ptr].v] = d[v] + reb[ptr].w;
							p[reb[ptr].v] = v;
							pr[reb[ptr].v] = ptr;
						}
		int v = T;
		while (v > 0) {
			int ptr = pr[v];
			reb[ptr].f ++;
			reb[ptr^1].f --;
			v = p[v];
		}	
	}
	seta (c, 0);
	for (int i = 0; i <= lst; i ++)
		if (reb[i].f == reb[i].c && reb[i].num >= 0)
			c[reb[i].num] = 1;
	forn (i, n) {
		printf ("%d", c[i]);
		if (i + 1 < n)
			printf (" ");
		else
			puts ("");
	}
	
	return 0;
}