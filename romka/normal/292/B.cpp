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

int n, m, x, y;
vector<int> g[100010];

int main() {
	scanf("%d %d", &n, &m);
	forn(i, m) {
		scanf("%d %d", &x, &y);
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}	

	bool bad = false;
	int c1 = 0;
	forn(i, n) {
		if (g[i].size() == 1) c1++;
		if (g[i].size() > 2) bad = true;
	}

	if (bad) {
		int tv = -1;
		forn(i, n)
			if (g[i].size() != 1)
				tv = i;

		if (tv == -1 || g[tv].size() != n - 1) printf("unknown topology\n");
		else {
			forn(i, n)
				if (i != tv)
					if (g[i].size() != 1 || g[i][0] != tv) {
						printf("unknown topology\n");
						return 0;
					}
			printf("star topology\n");
		}
	} else {
		if (c1 == 2) printf("bus topology\n");
		else if (c1 == 0) printf("ring topology\n");
			  else printf("unknown topology\n");
	}

	return 0;
}