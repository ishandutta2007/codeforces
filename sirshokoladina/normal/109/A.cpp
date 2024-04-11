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
	int n;
	cin >> n;
	forn (i, n / 4 + 1) {
		if ((n - 4 * i) % 7 == 0) {
			forn (j, i) {
				cout << 4;
			}
			forn (j, (n - 4 * i) / 7) {
				cout << 7;
			}
			return 0;
		}
	}
	cout << -1;
}