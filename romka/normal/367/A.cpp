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

char s[100010];
int f[100010][3];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	forn(i, n) {
		forn(j, 3) f[i+1][j] = f[i][j];
		f[i+1][s[i] - 'x']++;
	}
	int tc;
	scanf("%d", &tc);

	int l, r, c[5];
	forn(q, tc) {
		scanf("%d %d", &l, &r);
		forn(j, 3)
			c[j] = f[r][j] - f[l-1][j];

		c[3] = c[0];
		c[4] = c[1];

		bool ok = false;
		for (int w = 2; w <= 4; w++)
			if (c[w] >= c[w-1] && c[w] >= c[w-2] && c[w-1] >= c[w-2] && c[w] <= c[w-2] + 1)
				ok = true;

		if (ok || r - l + 1 < 3) printf("YES\n"); else printf("NO\n");
	}

	return 0;
}