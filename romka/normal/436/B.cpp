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

int n, m, ans[2010];
char s[2010];

int main() {
	scanf("%d %d %*d", &n, &m);
	forn(i, n) {
		scanf("%s", s);
		forn(j, m) {
			if (s[j] == 'U') {
				if (i % 2 == 0) ans[j]++;
			}
			if (s[j] == 'L') {
				if (j - i >= 0) ans[j - i]++;
			}
			if (s[j] == 'R') {
				if (j + i < m) ans[j + i]++;
			}
		}
	}

	forn(j, m) printf("%d ", ans[j]);
	printf("\n");

	return 0;
}