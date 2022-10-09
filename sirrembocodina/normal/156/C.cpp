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

const int64 mod = 1000000007;

int64 mult(int64 a, int64 b) {
	return (a * b) % mod;
}

int64 add(int64 a, int64 b) {
	return (a + b) % mod;
}

int d[2610][110];

int64 solve(int n, int m) {
	if (d[n][m] != -1) {
		return d[n][m];
	}
	d[n][m] = 0;
	forn (i, min(26, n + 1)) {
		d[n][m] = add(d[n][m], solve(n - i, m - 1));
	}
	return d[n][m];
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	forn (i, 2610) {
		forn (j, 110) {
			d[i][j] = -1;
		}
		d[i][0] = 0;
	}
	forn (j, 110) {
		d[0][j] = 1;
	}
	int t;
	cin >> t;
	forn (q, t) {
		string s;
		cin >> s;
		int n = 0;
		forv (i, s) {
			n += s[i] - 'a';
		}
		cout << add(solve(n, s.size()), mod - 1) << endl;
	}
}