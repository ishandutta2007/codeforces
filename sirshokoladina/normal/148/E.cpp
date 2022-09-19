#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <cstring>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i ++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i --)
#define sqr(a) ((a) * (a))
#define mp make_pair
#define pb push_back
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

int k[110];
int c[110][110];
int sl[110][110], sr[110][110], slr[110][110];
int d[110][10010];

int main() {
	//freopen ("input.txt", "rt", stdin);
	//freopen ("output.txt", "wt", stdout);
	memset(k, 0, sizeof k);
	memset(c, 0, sizeof c);
	memset(sl, 0, sizeof sl);
	memset(sr, 0, sizeof sr);
	memset(slr, 0, sizeof slr);
	memset(d, 0, sizeof d);
	int n, m;
	cin >> n >> m;
	forn (i, n) {
		cin >> k[i];
		forn (j, k[i]) {
			cin >> c[i][j];
		}
	}
	forn (i, n) {
		sl[i][0] = sr[i][0] = 0;
		forn (j, k[i]) {
			sl[i][j + 1] = sl[i][j] + c[i][j];
			sr[i][j + 1] = sr[i][j] + c[i][k[i] - 1 - j];
		}
		forn (j, k[i] + 1) {
			forn (q, k[i] - j + 1) {
				slr[i][j + q] = max(slr[i][j + q], sl[i][j] + sr[i][q]);
			}
		}
	}
	forn (i, n + 1) {
		forn (j, m + 1) {
			if (!i) {
				continue;
			}
			forn (q, min(j, k[i - 1]) + 1) {
				d[i][j] = max(d[i][j], d[i - 1][j - q] + slr[i - 1][q]);
			}
		}
	}
	cout << d[n][m];
	return 0;
}