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

int next[200500][26], l[200500], suf[200500];
int n, la;
char buf[200500];
int64 t[200500], ts[200500];

void add (int c) {
	c -= 'a';
	int v = n;
	n ++;
	l[v] = l[la] + 1;
	int p = la;
	la = v;
	while (p != -1 && next[p][c] == -1) {
		next[p][c] = v;
		p = suf[p];
	}
	if (p == -1) {
		suf[la] = 0;
		return;
	}
	int q = next[p][c];
	if (l[p] + 1 == l[q]) {
		suf[la] = q;
		return;
	}
	int r = n;
	n ++;
	suf[r] = suf[q];
	suf[q] = r;
	l[r] = l[p] + 1;
	suf[la] = r;
	memcpy (next[r], next[q], sizeof (next[q]));
	while (p != -1 && next[p][c] == q) {
		next[p][c] = r;
		p = suf[p];
	}
}

void dfs (int v) {
	if (t[v] != -1)
		return;
	t[v] = 0;
	forn (i, 26)
		if (next[v][i] != -1) {
			dfs (next[v][i]);
			ts[v] += ts[next[v][i]];
			t[v] += t[next[v][i]];
		}
	t[v] += ts[v];
}

void print (int v, int k) {
	if (k <= ts[v]) {
		cout << endl;
		return;
	}
	k -= ts[v];
       	forn (i, 26)
       		if (next[v][i] != -1)
       			if (t[next[v][i]] < k)
       				k -= t[next[v][i]];
			else {
				printf ("%c", 'a' + i);
				print (next[v][i], k);
				return;
			}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
	seta (next, 255);
	seta (l, 0);
	seta (suf, 255);
	n = 1;
	la = 0;
	scanf ("%s", buf);
	int len = strlen (buf);
	forn (i, len)
		add (buf[i]);
	seta (t, 255);
	seta (ts, 0);
	int v = la;
	while (v >= 0) {
		ts[v] ++;
		v = suf[v];
	}
	dfs (0);
	int k;
	cin >> k;
	k += ts[0];
	if (t[0] < k) {
		cout << "No such line." << endl;
		return 0;
	}
	print (0, k);
	return 0;
}