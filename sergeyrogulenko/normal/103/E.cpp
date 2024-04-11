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
	int v, c, f, next;
};

int n, list, iter;
int u[310];
int ma[300];
int a[300][300];
int ver[302];
rec reb[200000];
int cost[300], S, T;
int minC;

bool go (int v) {
	if (u[v])
		return 0;
	u[v] = 1;
	forn (i, n)
		if (a[v][i])
			if (ma[i] == -1 || go (ma[i])) {
				ma[i] = v;
				return 1;
			}
	return 0;
}

void push_ (int v1, int v2, int c) {
	list ++;
	reb[list].v = v2;
	reb[list].next = ver[v1];
	reb[list].f = 0;
	reb[list].c = c;
	ver[v1] = list;
}

void push (int v1, int v2, int c) {
	push_ (v1, v2, c);
	push_ (v2, v1, 0);
}

int dfs (int v, int cur) {
	if (u[v] == iter)
		return 0;
	if (v == T)
		return cur;
	u[v] = iter;
	for (int ptr = ver[v]; ptr != -1; ptr = reb[ptr].next)
		if (reb[ptr].c - reb[ptr].f >= minC) {
			int f = dfs (reb[ptr].v, min (cur, reb[ptr].c-reb[ptr].f));
			if (f) {
				reb[ptr].f += f;
				reb[ptr^1].f -= f;
				return f;
			}
		}
	return 0;
}

int max_flow () {
	minC = 1 << 25;
	int res = 0;
	seta (u, 0);
	iter = 0;
	while (minC > 0) {
		iter ++;
		int f;
		while (f = dfs (S, inf)) {
			res += f;
			iter ++;
		}
		minC /= 2;
	}
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta (a, 0);
	scanf ("%d", &n);
	forn (i, n) {
		int k;
		scanf ("%d", &k);
		forn (j, k) {
			int x;
			scanf ("%d", &x);
			x --;
			a[i][x] = 1;
		}
	}
	forn (i, n)
		scanf ("%d", &cost[i]);
	seta (ma, 255);
	forn (i, n) {
		seta (u, 0);
		go (i);
	}
	seta (ver, 255);
	list = -1;
	forn (i, n) {
		seta (u, 0);
		go (i);
		forn (j, n)
			if (u[j])
				push (i, j, inf);
	}
	int left = 0;
	S = n;
	T = n+1;
	forn (i, n)
		if (cost[i] < 0) {
			left += -cost[i];
			push (S, i, -cost[i]);
		} else
			push (i, T, cost[i]);
	cout << max_flow () - left << endl;
	return 0;
}