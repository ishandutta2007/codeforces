#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

bool d[500][500][2][2];

int dx[100], dy[100];

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int x0, y0, n, r;
	cin >> x0 >> y0 >> n >> r;
	forn (i, n) {
		cin >> dx[i] >> dy[i];
	}
	forn (i, 500) {
		forn (j, 500) {
			forn (k, 2) {
				forn (l, 2) {
					d[i][j][k][l] = ((i - 250) * (i - 250) + (j - 250) * (j - 250) > r * r);
				}
			}
		}
	}
	forn (s, 1000) {
		forn (i, 500) {
			forn (k, 2) {
				forn (l, 2) {
					int j = s - i - k - l;
					if (j >= 0 && j < 500) {
						if (!d[i][j][k][l]) {
							if (k) {
								d[i][j][k][l] |= !d[j][i][l][0];
							}
							forn (e, n) {
								int i1 = i - dx[e];
								int j1 = j - dy[e];
								if (i1 >= 0 && j1 >= 0) {
									d[i][j][k][l] |= !d[i1][j1][l][k];
								}
							}
						}
					}
				}
			}
		}
	}
	cout << (d[250 - x0][250 - y0][1][1] ? "Anton" : "Dasha");
}