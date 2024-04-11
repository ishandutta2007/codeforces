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

int p[1000100][20], l[1000100];
int q[1000100];

int up (int a, int k) {
	forn (i, 20) {
		if (k & (1 << i)) {
			a = p[a][i];
		}
	}
	return a;
}

int lca (int a, int b) {
	if (l[a] < l[b]) {
		swap(a, b);
	}
	a = up(a, l[a] - l[b]);
	if (a == b) {
		return a;
	}
	ford (i, 20) {
		if (p[a][i] != p[b][i]) {
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int main () {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	p[0][0] = p[1][0] = p[2][0] = p[3][0] = 0;
	l[0] = 0, l[1] = l[2] = l[3] = 1;
	int Q;
	cin >> Q;
	forn (i, Q) {
		scanf("%d", &q[i]);
		q[i]--;
		p[4 + 2 * i][0] = q[i];
		p[5 + 2 * i][0] = q[i];
		l[4 + 2 * i] = l[5 + 2 * i] = l[q[i]] + 1;
	}
	int n = 4 + 2 * Q;
	forn (j, 19) {
		forn (i, n) {
			p[i][j + 1] = p[p[i][j]][j];
		}
	}
	int cv = 0;
	bool ce = 0;
	int d = 2;
	forn (i, Q) {
		int a = lca(q[i], cv);
		int cur;
		if (!ce) {
			cur = 2 * (l[q[i]] + l[cv] - 2 * l[a]);
		} else {
			if (a == cv) {
				cur = 2 * (l[q[i]] + l[cv] - 2 * l[a]) + 1;
			} else {
				cur = 2 * (l[q[i]] + l[cv] - 2 * l[a]) - 1;
			}
		}
		if (cur == d) {
			if (!ce) {
				if (a == cv) {
					cv = up(q[i], l[q[i]] - l[cv] - 1);
					ce = 1;
				} else {
					ce = 1;
				}
			} else {
				if (a == cv) {
					ce = 0;
				} else {
					cv = p[cv][0];
					ce = 0;
				}
			}
			++d;
		}
		printf("%d\n", d);
//		cerr << cv << ' ' << ce << endl;
	}
	return 0;
}