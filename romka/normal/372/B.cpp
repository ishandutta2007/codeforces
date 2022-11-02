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

int n, m, q;
char a[55][55];
int f[55][55][55][55], s[55][55];

bool ok(int a, int b, int c, int d) {
	return s[c][d] - s[a-1][d] - s[c][b-1] + s[a-1][b-1] == 0;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	forn(i, n) {
		scanf("%s", a[i+1] + 1);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (a[i][j] - '0');

	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			for (int i2 = i; i2 <= n; i2++)
				for (int j2 = j; j2 <= m; j2++) {
					f[i][j][i2][j2] = f[i][j+1][i2][j2] + f[i][j][i2][j2-1] - f[i][j+1][i2][j2-1];
					int cc = 0;
					for (int q = i; q <= i2; q++) {
						if (ok(q, j, q, j2)) cc++;
						else cc = 0;
						f[i][j][i2][j2] += cc;
					}
				}

	int li, lj, ri, rj;
	forn(w, q) {
		scanf("%d %d %d %d", &li, &lj, &ri, &rj);
		printf("%d\n", f[li][lj][ri][rj]);
	}

	return 0;
}