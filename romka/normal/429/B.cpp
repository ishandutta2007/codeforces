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

int n, m, a[1010][1010];
ll tlf[1010][1010], trf[1010][1010], dlf[1010][1010], drf[1010][1010];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) tlf[i][j] = max(tlf[i-1][j], tlf[i][j-1]) + a[i][j];
	for (int i = 1; i <= n; i++) for (int j = m; j >= 1; j--) trf[i][j] = max(trf[i-1][j], trf[i][j+1]) + a[i][j];
	for (int i = n; i >= 1; i--) for (int j = 1; j <= m; j++) dlf[i][j] = max(dlf[i+1][j], dlf[i][j-1]) + a[i][j];
	for (int i = n; i >= 1; i--) for (int j = m; j >= 1; j--) drf[i][j] = max(drf[i+1][j], drf[i][j+1]) + a[i][j];

	ll ans = 0;
	for (int i = 2; i <= n - 1; i++)
		for (int j = 2; j <= m - 1; j++) {
			ans = max(ans, tlf[i-1][j] + drf[i+1][j] + dlf[i][j-1] + trf[i][j+1]);
			ans = max(ans, tlf[i][j-1] + drf[i][j+1] + dlf[i+1][j] + trf[i-1][j]);
		}

	cout << ans << endl;

	return 0;
}