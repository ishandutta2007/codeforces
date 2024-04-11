#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.141592653589793238462643l;

int n, d, a[110], x[110], y[110];

int l[110];
int e[110][110];

int main () {
#ifdef LOCAL
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	cin >> n >> d;
	forn (i, n - 2) {
		cin >> a[i + 1];
	}
	a[0] = a[n - 1] = 0;
	forn (i, n) {
		cin >> x[i] >> y[i];
	}
	forn (i, n) {
		forn (j, n) {
			if (i == j) {
				e[i][j] = 0;
			} else {
				e[i][j] = d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) - a[i];
			}
		}
	}
	forn (i, n) {
		l[i] = 1000000000;
	}
	l[0] = 0;
	forn (i, n) {
		forn (j, n) {
			forn (k, n) {
				l[k] = min(l[k], l[j] + e[j][k]);
			}
		}
	}
	cout << l[n - 1] << endl;
	return 0;
}