#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.141592653589793238462643l;

ld y[310][310];

pair<ld, ld> isct (int i1, int i2, int j) {
	ld y0 = y[i1][j], y1 = y[i1][j + 1];
	ld z0 = y[i2][j], z1 = y[i2][j + 1];
	ld x = (y0 - z0) / (y0 - y1 - z0 + z1);
	return mp(x, y0 + (y1 - y0) * x);
}

ld ans[310];

int main () {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n, k;
	cin >> n >> k;
	forn (i, n) {
		forn (j, k + 1) {
			cin >> y[i][j];
		}
	}
	forn (i, k) {
		vector<int> v;
		vector<pair<ld, ld> > p;
		p.pb(mp(0.5, -1));
		ld s = 0;
		forn (j, n) {
			ld y0 = y[j][i], y1 = y[j][i + 1];
			int l = 0;
			while (l < (int)p.size() && p[l].sc + 1e-10 > y0 + (y1 - y0) * p[l].fs) {
				l++;
			}
			int r = l;
			while (r < (int)p.size() && p[r].sc + 1e-10 < y0 + (y1 - y0) * p[r].fs) {
				r++;
			}
			if (r != l) {
				pair<ld, ld> p1, p2;
				if (l == 0) {
					p1 = mp(0, y0);
				} else {
					p1 = isct(v[l - 1], j, i);
				}
				if (r == (int)p.size()) {
					p2 = mp(1, y1);
				} else {
					p2 = isct(v[r - 1], j, i);
				}
				v.erase(v.begin() + l, v.begin() + r - 1);
				v.insert(v.begin() + l, j);
				p.erase(p.begin() + l, p.begin() + r);
				p.insert(p.begin() + l, p2);
				p.insert(p.begin() + l, p1);
			}
			ld s1 = 0;
			forn (t, p.size() - 1) {
				s1 += (p[t + 1].fs - p[t].fs) * (p[t + 1].sc + p[t].sc) / 2;
			}
			ans[j] += s1 - s;
			s = s1;
		}
	}
	forn (i, n) {
		printf("%0.10lf\n", (double)ans[i]);
	}
	return 0;
}