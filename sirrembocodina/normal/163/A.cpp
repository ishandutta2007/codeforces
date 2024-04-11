#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define forab(i, a, b) for (int i = a; i < (int)(b); ++i)
#define fordab(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); --i)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((x) * (x))

typedef long long int64;
typedef long double ld;

const int mod = 1000000007;

int d[5100][5100];
int last[26][5100], sm[5100][5100];

inline int sum(int a, int b) {
	int c = a + b;
	if (c >= mod) {
		c -= mod;
	}
	return c;
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	string s, t;
	cin >> s >> t;
	forv (i, s) {
		forv (j, t) {
			sm[i][j] = d[i][j] = s[i] == t[j];
			if (j) {
				sm[i][j] += sm[i][j - 1];
			}
		}
	}
	forn (i, 26) {
		last[i][0] = -1;
	}
	forv (i, t) {
		forn (j, 26) {
			last[j][i + 1] = last[j][i];
		}
		last[t[i] - 'a'][i + 1] = i;
	}
	forab (i, 1, s.size()) {
		forv (j, t) {
			if (s[i] == t[j]) {
//				int p = last[s[i - 1] - 'a'][j];
				if (j) {
					d[i][j] = sum(d[i][j], sm[i - 1][j - 1]);
				}
			}
			if (j) {
				sm[i][j] = sum(d[i][j], sm[i][j - 1]);
			}
		}
	}
	int ans = 0;
	forv (i, s) {
		forv (j, t) {
			ans = sum(ans, d[i][j]);
/*			if (d[i][j]) {
				cout << i << " " << j << " " << d[i][j] << endl;
			}
*/		}
	}
	cout << ans;
}