#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

int a[2000];
int d[2000][2000];
int p[2000][2000], q[2000][2000];
int X[2000][2000], Y[2000][2000];

int main() {
	int n;
	cin >> n;
	forn (i, n) {
		cin >> a[i];
	}
	forn (i, 2000) {
		forn (j, 2000) {
			if (i >= n && j >= n) {
				d[i][j] = 0;
			} else {
				d[i][j] = 1000000000;
			}
			p[i][j] = q[i][j] = -1;
			X[i][j] = Y[i][j] = 1500;
		}
	}
	for (int i = n; i > 0; i--) {
		forn (j, i) {
			if (i == n) {
				d[i][j] = a[j];
				p[i][j] = j;
			} else if (i == n - 1) {
				d[i][j] = max(a[i], a[j]);
				p[i][j] = j, q[i][j] = i;
			} else {
				if (d[i][j] > d[i + 2][i + 1] + max(a[i], a[j])) {
					d[i][j] = d[i + 2][i + 1] + max(a[i], a[j]);
					p[i][j] = j;
					q[i][j] = i;
					X[i][j] = i + 2;
					Y[i][j] = i + 1;
				}
				if (d[i][j] > d[i + 2][i] + max(a[i + 1], a[j])) {
					d[i][j] = d[i + 2][i] + max(a[i + 1], a[j]);
					p[i][j] = j;
					q[i][j] = i + 1;
					X[i][j] = i + 2;
					Y[i][j] = i;
				}
				if (d[i][j] > d[i + 2][j] + max(a[i], a[i + 1])) {
					d[i][j] = d[i + 2][j] + max(a[i], a[i + 1]);
					p[i][j] = i;
					q[i][j] = i + 1;
					X[i][j] = i + 2;
					Y[i][j] = j;
				}
			}
		}
	}
	cout << d[1][0] << endl;
	int x = 1, y = 0;
	while (p[x][y] > -1) {
		cout << p[x][y] + 1 << ' ';
		if (q[x][y] > -1) {
			cout << q[x][y] + 1 << ' ';
		}
		cout << endl;
		int x1 = X[x][y], y1 = Y[x][y];
		x = x1, y = y1;
	}
}