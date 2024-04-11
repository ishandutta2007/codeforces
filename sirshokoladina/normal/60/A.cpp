#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	string s;
	int n, k, a, b, x, y;
	cin >> n >> k;
	x = 0; y = n + 1;
	forn (i, k) {
		cin >> s;
		cin >> s;
		cin >> s;
		b = (s == "left") ? 0 : 1;
		cin >> s;
		cin >> a;
		if (!b) {
			y = min(y, a);
		} else {
			x = max(x, a);
		}
	}
	int q = y - x - 1;
	cout << ((q > 0) ? q : -1);
}