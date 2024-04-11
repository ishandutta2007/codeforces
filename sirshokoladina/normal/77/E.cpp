#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
typedef long double ld;

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int k;
	cin >> k;
	forn (i, k) {
		ld D, d;
		int n;
		cin >> D >> d >> n;
		ld r = (D - d) / 2;
		ld x = (D + d) / 2;
		ld y = 2 * n * r;
		ld l = sqrtl(x * x + y * y);
		ld ans = ((1. / (l - r)) - (1. / (l + r))) * d * D;
		printf("%0.10f\n", (double)ans);
	}
}