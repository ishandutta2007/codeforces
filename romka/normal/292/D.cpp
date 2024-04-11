#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, m, l, r, k, x[20010], y[20010];
int pl[10010][510], pr[10010][510];

struct SNM {
	vector<int> p;

	SNM(int n) {
		p.resize(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
	}

	void init() {
		forn(i, n) p[i] = i;
	}

	int findset(int x) {
		return x == p[x] ? x : p[x] = findset(p[x]);
	}

	void link(int a, int b) {
		a = findset(a);
		b = findset(b);

		if (b & 1) p[a] = b;
		else p[b] = a;
	}
};

int main() {
	scanf("%d %d", &n, &m);
	forn(i, m) {
		scanf("%d %d", &x[i], &y[i]);
		x[i]--, y[i]--;
	}
	SNM snm(n);

	forn(i, m) {
		if (snm.findset(x[i]) != snm.findset(y[i]))
			snm.link(x[i], y[i]);
		forn(j, n) pl[i][j] = snm.p[j];
	}

	snm.init();
	for (int i = m-1; i>=0; i--) {
		if (snm.findset(x[i]) != snm.findset(y[i]))
			snm.link(x[i], y[i]);
		forn(j, n) pr[i][j] = snm.p[j];
	}

	scanf("%d", &k);
	forn(i, k) {
		scanf("%d %d", &l, &r);
		l--, r--;
		int ans = n;
		snm.init();
		if (l > 0) {
			l--;
			forn(j, n) {
				if (snm.findset(j) != snm.findset(pl[l][j])) {
					snm.link(j, pl[l][j]);
					ans--;
				}
			}
		}
		if (r < m-1) {
			r++;
			forn(j, n) {
				if (snm.findset(j) != snm.findset(pr[r][j])) {
					snm.link(j, pr[r][j]);
					ans--;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}