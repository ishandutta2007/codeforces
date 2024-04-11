#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

char buf[300500];
string s[3];
int la, n, suf[600500], l[600500], ne[600500][29];
int t[600500];

void add (int c) {
	int p, q, r;
	p = la;
	n ++;
	la = n;
	l[la] = l[p] + 1;
	while ((p > 0) && (ne[p][c] == 0)) {
		ne[p][c] = la;
		p = suf[p];
	}
	if (p == 0) {
		suf[la] = 1;
		return;
	}
	q = ne[p][c];
	if (l[q] == l[p] + 1) {
		suf[la] = q;
		return;
	}
	n ++;
	r = n;
	l[r] = l[p] + 1;
	suf[r] = suf[q];
	suf[q] = r;
	suf[la] = r;
	memcpy (ne[r], ne[q], sizeof (ne[q]));
	while ((p != 0) && (ne[p][c] == q)) {
		ne[p][c] = r;
		p = suf[p];
	} 
}

int64 d[600500][3];

void dfs(int v) {
	if (t[v] != -1) return;
	t[v] = 0;
	forn(i, 29)
		if (ne[v][i] != 0) {
			dfs(ne[v][i]);
		}
	forn(i, 26)
		if (ne[v][i] != 0) {
			t[v] |= t[ne[v][i]];
			forn(j, 3)
				d[v][j] += d[ne[v][i]][j];
		}
	forn(i, 3)
		if (ne[v][i+26] != 0)
			t[v] |= 1 << i;
}

int64 addd[600500];
const int64 P = 1000000007;

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
        forn(i, 3) {
        	scanf("%s", buf);
        	s[i] = buf;
        }
	n = 1;
	la = 1;
	seta (suf, 0);
	seta (ne, 0);
	seta (l, 0);
	forn(i, 3) {
		forn(j, s[i].length())
			add(s[i][j] - 'a');
		add(26 + i);
	}
	seta(t, 255);
	seta(d, 0);
	forn(i, 3) {
		int v = 1;
		forn(j, s[i].length())
			v = ne[v][s[i][j]-'a'];
		while (v != 0) {
			d[v][i] = 1;
			v = suf[v];
		}
	}
	dfs(1);

	seta(addd, 0);
	for(int i = 1; i <= n; i++) {
		if (t[i] == 7) {
			int64 cnt = d[i][0] * d[i][1] % P * d[i][2] % P;
			int lf, rg;
			rg = l[i];
			lf = l[suf[i]] + 1;
			addd[lf] = (addd[lf] + cnt) % P;
			addd[rg+1] = (addd[rg+1] - cnt + P) % P;
		}
	}
	int m = min(s[0].length(), min(s[1].length(), s[2].length()));
	int64 cur = 0;
	for(int i = 1; i <= m; i++) {
		cur = (cur + addd[i]) % P;
		printf("%d ", I cur);
	}
	return 0;
}