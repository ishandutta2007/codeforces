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

int n, m;
char s[55][55];
int u[256];

int main() {
	scanf("%d %d", &n, &m);
	forn(i, n) scanf("%s", s[i]);
	int ans = 0;
	int it = 0;
	forn(i, n - 1) forn(j, m - 1) {
		it++;
		forn(q, 2) forn(w, 2) {
			u[s[i+q][j+w]] = it;
		}
		if (u['a'] == it && u['f'] == it && u['c'] == it && u['e'] == it) ans++;
	}
	printf("%d\n", ans);
	return 0;
}