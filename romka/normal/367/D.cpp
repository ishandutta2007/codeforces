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

int n, m, k, d, x, a[100010], p[100010][20], f[1 << 20], pprev[20];
vector<int> am[22];
int bc[1 << 20], jj[22], kj;

int main() {
	scanf("%d %d %d", &n, &m, &d);
	forn(i, m) {
		scanf("%d", &k);
		forn(j, k) {
			scanf("%d", &x);
			x--;
			a[x] = i;
		}
	}

	memset(pprev, 0xff, sizeof(pprev));
	forn(i, n) {
		forn(j, m) p[i][j] = pprev[j];
		pprev[a[i]] = i;
	}
	forn(j, m) p[n][j] = pprev[j];

	bc[0] = 0;
	for (int i = 1; i < (1 << 20); i++)
		bc[i] = bc[i & (i-1)] + 1;

	forn(mask, 1 << m)
		am[bc[mask]].pb(mask);

	forn(q, m)
		forn(i, am[q].size()) {

		int mask = am[q][i];
		f[mask] = n;

		if (mask == 0) {
			continue;
		}

		int bpos = n + 1, bpm = -1;
		kj = 0;
		forn(j, m)
			if (mask & (1 << j)) {
				int pm = mask ^ (1 << j);
				if (f[pm] < bpos) {
					bpos = f[pm];
					bpm = pm;
				}
				jj[kj++] = j;
			}

		while (bpos > -1) {
			int np = n + 1;
			forn(qj, kj) {
				int j = jj[qj];
				if (p[bpos][j] >= bpos - d)
					if (p[bpos][j] < np)
						np = p[bpos][j];
			}

			if (np == n + 1) break;
			else bpos = np;
		}

		f[mask] = bpos;

		if (bpos == -1) {
			printf("%d\n", q);
			return 0;
		}
	}

	printf("%d\n", m);

	return 0;
}