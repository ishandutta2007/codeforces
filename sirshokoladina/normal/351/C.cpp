#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <algorithm>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

typedef vector<vector<ui> > mat;

mat operator * (const mat &a, const mat &b) {
	mat c(a.size(), vector<ui>(a.size(), 2000000010));
	forn (i, a.size()) {
		forn (j, a.size()) {
			forn (k, a.size()) {
				c[i][k] = min(c[i][k], a[i][j] + b[j][k]);
			}
		}
	}
	return c;
}

mat pw (mat a, int n) {
	mat b(a.size(), vector<ui>(a.size(), 2000000010));
	forn (i, a.size()) {
		b[i][i] = 0;
	}
	while (n) {
		if (n & 1) {
			b = a * b;
		}
		a = a * a;
		n >>= 1;
	}
	return b;
}

int n, m;
ui a[100], b[100];

ui d[100][100];

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	cin >> n >> m;
	forn (i, n) {
		cin >> a[i];
	}
	forn (i, n) {
		cin >> b[i];
	}
	mat x(50, vector<ui>(50));
	forn (i, 50) {
		forn (j, n + 1) {
			forn (k, 50) {
				d[j][k] = 2000000010;
				if (!j) {
					if (k == i) {
						d[j][k] = 0;
					}
				} else {
					if (k) {
						d[j][k] = min(d[j][k], d[j - 1][k - 1] + a[j - 1]);
					}
					if (k + 1 < 50) {
						d[j][k] = min(d[j][k], d[j - 1][k + 1] + b[j - 1]);
					}
				}
			}
		}
		forn (j, 50) {
			x[i][j] = d[n][j];
		}
	}
	cout << pw(x, m)[0][0] << endl;
	return 0;
}