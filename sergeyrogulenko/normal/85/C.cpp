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

int n;
int p[100100], l[100100], r[100100], L[100100], R[100100], dp[100100];
int w[100100];
int q[100100], next[100100];
int64 S[100100];
int root;

void go (int v, int DP) {
	dp[v] = DP;
	L[v] = R[v] = w[v];
	if (l[v] != -1) {
		go (l[v], DP+1);
		go (r[v], DP+1);
		L[v] = L[l[v]];
		R[v] = R[r[v]];
	}
	q[0] ++;
	q[q[0]] = v;
}

set <pii> T;
vector <pii> LST;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	forn (i, n) {
		scanf ("%d%d", &p[i], &w[i]);
		p[i] --;
		if (p[i] < 0) {
			p[i] = -1;
			root = i;
		}
	}
	forn (i, n)
		l[i] = r[i] = -1;
	forn (i, n)
		if (p[i] != -1) {
			if (w[i] < w[p[i]])
				l[p[i]] = i;
			else
				r[p[i]] = i;
		}
	q[0] = 0;
	go (root, 0);
	seta (S, 0);
	for (int i = q[0]; i >= 1; i --) {
		int v = q[i];
		if (p[v] == -1)
			continue;
		S[v] = S[p[v]];
		if (w[v] < w[p[v]])
			S[v] += (int64)L[r[p[v]]];
		else
			S[v] += (int64)R[l[p[v]]];
	}
	forn (i, n)
		T.insert (mp (w[i], i));
	seta (next, 255);
	for (set <pii> :: iterator it = T.begin(); it != T.end(); it ++) {
		int v = it->sc;
		it ++;
		if (it == T.end())
			break;
		next[it->sc] = v;
		it --;
	}
	LST.clear ();
	forn (i, n)
		if (l[i] == -1)
			LST.pb (mp (w[i], i));
	sort (all (LST));
	int m;
	scanf ("%d", &m);
	forn (i, m) {
		int x;
		scanf ("%d", &x);
		vector <pii> :: iterator it = lower_bound (all (LST), mp (x, -1));
		if (it == LST.end())
			it --;
		int v = it->sc;
		int v1 = next[v];
		if (v1 != -1 && x < w[v1])
			it --;
		v = it->sc;
		printf ("%.10lf\n", (double)S[v] / (double)dp[v]);
	}
	return 0;
}