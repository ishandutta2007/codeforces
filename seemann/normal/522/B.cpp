#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <complex>

using namespace std;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
	
typedef long long ll;
typedef long double ldb;

const int MAXN = 200010;

int n;
int w[MAXN];
int h[MAXN];
int mx = 0, mx2 = 0;
int sum = 0;

int main() {
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	forn(i, n) {
		scanf("%d%d", &w[i], &h[i]);
		sum += w[i];
		if (mx < h[i]) {
			mx2 = mx;
			mx = h[i];
		} else if (mx2 < h[i]) {
			mx2 = h[i];
		}
	}

	forn(i, n)
		printf("%d ", (sum - w[i]) * ((mx == h[i]) ? mx2 : mx));
	printf("\n");

	return 0;
}