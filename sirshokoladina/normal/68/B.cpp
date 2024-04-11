#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

int a[100000];

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n, k;
	cin >> n >> k;
	forn (i, n) {
		cin >> a[i];
	}
	double l = 0;
	double r = 10000010;
	while (r - l > 0.00000001) {
		double m = (l + r) / 2;
		double s1 = 0, s2 = 0;
		forn (i, n) {
			if (a[i] < m) {
				s1 += m - a[i];
			} else {
				s2 += a[i] - m;
			}
		}
		if (s1 <= s2 * (100. - k) / 100.) {
			l = m;
		} else {
			r = m;
		}
	}
	printf("%0.10f", l);
}