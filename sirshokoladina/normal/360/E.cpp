#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <algorithm>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

int v[20010], l[20010], r[20010], c[20010];

vector<int> e[20010];

ll d1[20010], d2[20010];

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n, m, k;
	cin >> n >> m >> k;
	int s1, s2, f;
	cin >> s1 >> s2 >> f;
	s1--;
	s2--;
	f--;
	forn (i, m) {
		int x, y, c;
		cin >> x >> y >> c;
		x--;
		y--;
		e[x].pb(i);
		v[i] = y;
		l[i] = r[i] = c;
	}
	forn (i, k) {
		int	x, y, s, t;
		cin >> x >> y >> s >> t;
		x--;
		y--;
		e[x].pb(i + m);
		v[i + m] = y;
		l[i + m] = s;
		r[i + m] = t;
	}
	forn (i, n) {
		d1[i] = d2[i] = 1000000000000000000ll;
	}
	d1[s1] = 0;
	d2[s2] = 0;
	set<pair<ll, pair<int, int> > > s;
	forn (i, n) {
		s.insert(mp(d1[i], mp(i, 0)));
		s.insert(mp(d2[i], mp(i, 1)));
	}
	while (s.size()) {
		int q = s.begin()->sc.sc;
		int x = s.begin()->sc.fs;
		s.erase(s.begin());
		forn (i, e[x].size()) {
			int j = e[x][i];
			if (d1[x] < d2[x]) {
				c[j] = l[j];
			} else {
				c[j] = r[j];
			}
			if (q == 0) {
				int to = v[j];
				ll cur = d1[x] + c[j];
				if (d1[to] > cur) {
					s.erase(mp(d1[to], mp(to, 0)));
					d1[to] = cur;
					s.insert(mp(d1[to], mp(to, 0)));
				}
			} else {
				int to = v[j];
				ll cur = d2[x] + c[j];
				if (d2[to] > cur) {
					s.erase(mp(d2[to], mp(to, 1)));
					d2[to] = cur;
					s.insert(mp(d2[to], mp(to, 1)));
				}
			}
		}
	}
	if (d1[f] < d2[f]) {
		puts("WIN");
		forn (i, k) {
			cout << c[m + i] << ' ';
		}
		cout << endl;
		return 0;
	}
	forn (i, n) {
		d1[i] = d2[i] = 1000000000000000000ll;
	}
	d1[s1] = 0;
	d2[s2] = 0;
	s.clear();
	forn (i, n) {
		s.insert(mp(d1[i], mp(i, 0)));
		s.insert(mp(d2[i], mp(i, 1)));
	}
	while (s.size()) {
		int q = s.begin()->sc.sc;
		int x = s.begin()->sc.fs;
		s.erase(s.begin());
		forn (i, e[x].size()) {
			int j = e[x][i];
			if (d1[x] <= d2[x]) {
				c[j] = l[j];
			} else {
				c[j] = r[j];
			}
			if (q == 0) {
				int to = v[j];
				ll cur = d1[x] + c[j];
				if (d1[to] > cur) {
					s.erase(mp(d1[to], mp(to, 0)));
					d1[to] = cur;
					s.insert(mp(d1[to], mp(to, 0)));
				}
			} else {
				int to = v[j];
				ll cur = d2[x] + c[j];
				if (d2[to] > cur) {
					s.erase(mp(d2[to], mp(to, 1)));
					d2[to] = cur;
					s.insert(mp(d2[to], mp(to, 1)));
				}
			}
		}
	}
	if (d1[f] <= d2[f]) {
		puts("DRAW");
		forn (i, k) {
			cout << c[m + i] << ' ';
		}
		cout << endl;
		return 0;
	}
	puts("LOSE");
	return 0;
}