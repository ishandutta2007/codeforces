#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <queue>
#include <deque>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef double ld;
typedef long long int64;

int q[110], p[110], s[110], a[110], b[110];

int main() {
	int n, k;
	cin >> n >> k;
	forn (i, n) {
		cin >> q[i];
		--q[i];
		p[q[i]] = i;
		a[i] = i;
	}
	forn (i, n) {
		cin >> s[i];
		--s[i];
	}
	int f = 1000000;
	forn (j, k) {
		bool eq = true;
		forn (l, n) {
			if (a[l] != s[l]) {
				eq = false;
				break;
			}
		}
		if (eq) {
			f = j;
			break;
		}
		forn (l, n) {
			b[l] = a[q[l]];
		}
		forn (l, n) {
			a[l] = b[l];
		}
	}
	if (f > k) {
		bool eq = true;
		forn (l, n) {
			if (a[l] != s[l]) {
				eq = false;
				break;
			}
		}
		if (eq) {
			f = k;
		}
	}
	forn (i, n) {
		a[i] = i;
	}
	int g = 1000000;
	forn (j, k) {
		bool eq = true;
		forn (l, n) {
			if (a[l] != s[l]) {
				eq = false;
				break;
			}
		}
		if (eq) {
			g = j;
			break;
		}
		forn (l, n) {
			b[l] = a[p[l]];
		}
		forn (l, n) {
			a[l] = b[l];
		}
	}
	if (g > k) {
		bool eq = true;
		forn (l, n) {
			if (a[l] != s[l]) {
				eq = false;
				break;
			}
		}
		if (eq) {
			g = k;
		}
	}
	//cerr << f << " " << g << endl;
	if (f <= k && (k - f) % 2 == 0) {
		if (k == 1 || f > 1 || g > 1) {
			cout << "YES\n";
			return 0;
		}
	}
	if (g <= k && (k - g) % 2 == 0) {
		if (k == 1 || f > 1 || g > 1) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}