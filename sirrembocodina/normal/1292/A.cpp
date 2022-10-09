#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back

int a[2][100100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	int q;
	cin >> q;
	forn (i, q) {
		int x, y;
		cin >> x >> y;
		--x;
		forn (j, 3) {
			if (a[x][y]) {
				cnt -= a[1 - x][y - 1 + j];
			} else {
				cnt += a[1 - x][y - 1 + j];
			}
		}
		a[x][y] = 1 - a[x][y];
		if (cnt == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}