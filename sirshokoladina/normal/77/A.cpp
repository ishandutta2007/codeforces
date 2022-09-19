#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

string s[7] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
int a[7][7];

int read() {
	string t;
	cin >> t;
	forn (i, 7) {
		if (s[i] == t) {
			return i;
		}
	}
	return 0;
}

int mn = 1000000000, mx = -1;
int c[7];
int ex[3];
int num[3];

void rec(int k) {
	if (k == 7) {
		forn (i, 3) {
			num[i] = 0;
		}
		forn (i, 7) {
			num[c[i]]++;
		}
		int xx = 0, mxx = -1, mnx = 1000000000, nn = 0;
		forn (i, 3) {
			if (num[i]) {
				mxx = max(mxx, ex[i] / num[i]);
				mnx = min(mnx, ex[i] / num[i]);
			} else {
				return;
			}
		}
		xx = mxx - mnx;
		forn (i, 7) {
			forn (j, 7) {
				if (c[i] == c[j]) {
					nn += a[i][j];
				}
			}
		}
		if (xx < mn || (xx == mn && nn > mx)) {
			mn = xx;
			mx = nn;
		}
		return;
	}
	for (c[k] = 0; c[k] < 3; c[k]++) {
		rec(k + 1);
	}
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	forn (i, 7) {
		forn (j, 7) {
			a[i][j] = 0;
		}
	}
	int k;
	cin >> k;
	forn (i, k) {
		int x = read();
		int y = read();
		y = read();
		a[x][y] = 1;
	}
	forn (i, 3) {
		cin >> ex[i];
	}
	rec(0);
	cout << mn << ' ' << mx;
}