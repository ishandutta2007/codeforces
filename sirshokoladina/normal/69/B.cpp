#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

int mx[10000], co[10000];

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	forn (i, 10000) {
		mx[i] = 10000000;
		co[i] = 0;
	}
	int n, m;
	cin >> n >> m;
	forn (i, m) {
		int l, r, t, c;
		cin >> l >> r >> t >> c;
		for (int j = l - 1; j <= r - 1; j++) {
			if (mx[j] > t) {
				mx[j] = t;
				co[j] = c;
			}
		}
	}
	int s = 0;
	forn (i, n) {
		s += co[i];
	}
	cout << s << endl;
}