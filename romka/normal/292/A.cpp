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

int n, t[1010], c[1010];

int main() {
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d %d", &t[i], &c[i]);
	}	

	int i = 0, qs = 0;
	int ans = -1, ans2 = -1;
	for (int tc = 1; tc <= 1000000; tc++) {
		if (qs > 0) { ans = max(ans, tc); qs--; }
		if (i < n && t[i] == tc) qs += c[i++];
		if (qs > ans2) ans2 = qs;
	}
	if (qs > 0) ans = 1000000 + qs;
	printf("%d %d\n", ans, ans2);
	return 0;
}