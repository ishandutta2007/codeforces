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

struct rec {
	int m1, m2;
};

int h[500500], s[500500];
int n, m;
vector<int> g[500500];
rec q[500500];

bool operator < (const rec& p1, const rec& p2) {
	if (h[p1.m1] != h[p2.m1])
		return h[p1.m1] < h[p2.m1];
	if (p1.m1 != p2.m1)
		return p1.m1 < p2.m1;
	return h[p1.m2] < h[p2.m2];
}

void go(int v, int p, int m1, int m2) {
	if (h[v] < h[m1]) {
		m2 = m1;
		m1 = v;
	} else if (h[v] < h[m2]) {
		m2 = v;
	}
	q[v].m1 = m1;
	q[v].m2 = m2;
	forn(i, g[v].size())
		if (g[v][i] != p)
			go(g[v][i], v, m1, m2);
}

vector<int> u;
int cur;

void check(int l, int r) {
	int res = 0;
	forn(i, r - l + 1) {
		int hh = 0;
		if (i < I u.size()) {
			hh = u[i];
		} else {
			int dd = i - I u.size();
			if (cur + dd < m)
				hh = s[cur + dd];
		}
		res = max(res, hh - h[q[l].m1]);
		if (hh > h[q[l + i].m2]) return;
	}
	cout << res << endl;
	exit(0);
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &h[i]);
	}
	h[n] = inf;
	forn(i, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	scanf("%d", &m);
	forn(i, m)
		scanf("%d", &s[i]);
	sort(s, s + m);
	go(0, -1, n, n);
	sort(q, q + n);
	reverse(s, s + m);
	reverse(q, q + n);
	int mx = -1;
	forn(i, m)
		if (s[i] > h[q[i].m1])
			mx = i;
	if (mx == -1) {
		cout << 0 << endl;
		return 0;
	}
	u.clear();
	int l = -1;
	int r = -1;
	cur = 0;
	while (l < n) {
		l = r + 1;
		if (l == n) break;
		r = l;
		while (r + 1 < n && q[l].m1 == q[r + 1].m1) r++;
		if (u.size() <= (r - l + 1) && r >= mx) check(l, r);
		for (int i = l; i <= r; i++) {
			while (cur < m && s[cur] > h[q[i].m1]) {
				u.pb(s[cur]);
				cur++;
			}
			if (cur < m) cur++;
		}
	}
	cout << -1 << endl;
	return 0;
}