#include <bits/stdc++.h>

using namespace std;

constexpr int NMAX = 100000;
char tstr[NMAX], a[NMAX], b[NMAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		scanf("%s", tstr);
		bool predOne = false;
		for (int i = 0; i < n; ++i) {
			if (predOne) {
				a[i] = tstr[i], b[i] = '0';
				continue;
			}
			if (tstr[i] == '0') {
				a[i] = b[i] = '0';
			} else if (tstr[i] == '1') {
				a[i] = '0'; b[i] = '1';
				predOne = true;
			} else {
				a[i] = b[i] = '1';
			}
		}
		a[n] = b[n] = 0;
		printf("%s\n%s\n", a, b);
	}
}