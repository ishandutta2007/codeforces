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
	int n, m;
	cin >> n >> m;
	forn (i, n) {
		int s, f, t;
		scanf("%d%d%d", &s, &f, &t);
		if (s == f) {
			printf("%d\n", t);
			continue;
		}
		int k = t / (2 * (m - 1));
		t %= 2 * (m - 1);
		int a;
		if (t > 2 * m - 1 - s) {
			k++;
			t = 0;
		}
		if (t < s) {
			if (f >= s) {
				a = f - 1;
			} else {
				a = 2 * m - 1 - f;
			}
		} else {
			if (f <= s) {
				a = 2 * m - 1 - f;
			} else {
				a = 2 * m - 3 + f;
			}
		}
		printf("%d\n", a + k * 2 * (m - 1));
	}
}