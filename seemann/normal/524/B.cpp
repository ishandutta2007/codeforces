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

const int MAXN = 1010;
const int INF = 2e9;

int n;
int w[MAXN];
int h[MAXN];

int main() {
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);

	int minh = 0;

	forn(i, n) {
		scanf("%d%d", &w[i], &h[i]);
		minh = max(minh, min(w[i], h[i]));
	}

	int ans = INF;

	forab(H, minh, 1001) {
		int cur = 0;
		forn(i, n)
			if (w[i] <= H && h[i] <= H)
				cur += min(w[i], h[i]);
			else
				cur += max(w[i], h[i]);

		ans = min(ans, cur * H);
	}

	cout << ans << '\n';

	return 0;
}