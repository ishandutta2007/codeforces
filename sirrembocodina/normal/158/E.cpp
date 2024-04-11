#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long int64;
typedef unsigned int uint;

int d[4100][4100], l[4100], t[4100];

int main() {
	int n, k;
	cin >> n >> k;
/*	if (n == k) {
		cout << 86400;
		return 0;
	}
*/	forn (i, n) {
		cin >> l[i] >> t[i];
		l[i]--;
	}
	l[n] = 86400;
	t[n] = 0;
	n++;
	forn (i, n) {
		forn (j, k + 1) {
			d[i][j] = 2000000000;
		}
		d[i][i + 1] = 0;
	}
	d[0][0] = l[0] + t[0];
	forab (i, 1, n) {
		forn (j, k + 1) {
			if (j) {
				d[i][j] = min(d[i][j], d[i - 1][j - 1]);
			}
			d[i][j] = min(d[i][j], max(d[i - 1][j], l[i]) + t[i]);
//			cout << i << " " << j << " " << d[i][j] << endl;
		}
//		cout << endl;
	}
	int ans = l[0];
	forab (i, 1, n) {
		ans = max(ans, l[i] - d[i - 1][k]);
	}
	cout << ans;
}