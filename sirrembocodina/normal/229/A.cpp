#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forv(i, a) forn (i, a.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((x) * (x))

typedef long long int64;
typedef long double ld;

int b[110][30100];
char a[110][30100];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	forn (i, n) {
		scanf("%s", a[i]);
		forn (j, m) {
			a[i][j] -= '0';
			a[i][j + m] = a[i][j + m + m] = a[i][j];
		}
	}
	forn (i, n) {
		int last = -2000000000;
		forn (j, m + m + m) {
			if (a[i][j]) {
				last = j;
			}
			b[i][j] = j - last;
		}
		last = 2000000000;
		ford (j, m + m + m) {
			if (a[i][j]) {
				last = j;
			}
			b[i][j] = min(b[i][j], last - j);
		}
	}
	int ans = 1000000000;
	for (int j = m; j < (m << 1); ++j) {
		int res = 0;
		forn (i, n) {
			res += b[i][j];
			if (res >= 1000000000) {
				cout << -1;
				return 0;
			}
		}
		ans = min(ans, res);
	}
	cout << ans;
}