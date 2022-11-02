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

const int di[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dj[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m;
char a[1010][1010];
int u[1010][1010], d[1010][1010];
int q[1010 * 1010 * 2], qb, qf;
int si, sj, fi, fj;

int main() {
	scanf("%d %d", &n, &m);
	forn(i, n) scanf("%s", a[i]);
	forn(i, n) forn(j, m) {
		if (a[i][j] == 'S') si = i, sj = j;
		if (a[i][j] == 'E') fi = i, fj = j;
	}
	forn(i, n) forn(j, m) d[i][j] = int(1e9);
	qb = qf = 0;
	q[qf++] = fi;
	q[qf++] = fj;
	u[fi][fj] = 1;
	d[fi][fj] = 0;
	while (qb < qf) {
		int ci = q[qb++];
		int cj = q[qb++];

		forn(w, 4) {
			int ni = ci + di[w];
			int nj = cj + dj[w];

			if (ni >= 0 && ni < n && nj >= 0 && nj < m)
				if (a[ni][nj] != 'T' && !u[ni][nj]) {
					u[ni][nj] = 1;
					q[qf++] = ni; q[qf++] = nj;
					d[ni][nj] = d[ci][cj] + 1;
				}
		}
	}

	int md = d[si][sj];
	int ans = 0;
	forn(i, n)
		forn(j, m)
			if (a[i][j] >= '0' && a[i][j] <= '9') {
				int cc = a[i][j] - '0';
				if (d[i][j] <= md) {
					ans += cc;
				}
			}

	printf("%d\n", ans);

	return 0;
}