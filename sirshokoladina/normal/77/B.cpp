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
	int t;
	cin >> t;
	forn (i, t) {
		int a1, b1;
		double a, b;
		scanf("%d%d", &a1, &b1);
		a = a1, b = b1;
		if (b1 == 0) {
			printf("1\n");
			continue;
		}
		if (a1 == 0) {
			printf("0.5\n");
			continue;
		}
		double c = min(a, 4 * b);
		printf("%0.10f\n", (a - c) / a + c * c / (16. * a * b) + c / (2. * a));
	}
}