#include <bits/stdc++.h>

using namespace std;

int main() {
	int a; scanf("%d", &a);
	for (int n = a;; ++n) {
		int dsum = 0, cn = n;
		while (cn > 0) {
			dsum += cn % 10;
			cn /= 10;
		}
		if (dsum % 4 == 0) {
			printf("%d\n", n);
			return 0;
		}
	}
}