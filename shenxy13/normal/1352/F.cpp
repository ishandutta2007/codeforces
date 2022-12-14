#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		char ans[a + b + c + 1];
		if (b == 0) {
			if (a != 0) {
				for (int i = 0; i <= a + b + c; ++i) ans[i] = '0';
			} else {
				for (int i = 0; i <= a + b + c; ++i) ans[i] = '1';
			}
		} else if (b % 2) {
			int nz = (b + 1) / 2;
			for (int i = 1; i < nz; ++i) ans[2 * i - 2] = '0', ans[2 * i - 1] = '1';
			for (int i = 0; i <= a; ++i) ans[2 * nz - 2 + i] = '0';
			for (int i = 0; i <= c; ++i) ans[2 * nz - 1 + a + i] = '1';
		} else {
			int nz = b / 2;
			ans[0] = '1';
			for (int i = 1; i < nz; ++i) ans[2 * i - 1] = '0', ans[2 * i] = '1';
			for (int i = 0; i <= a; ++i) ans[2 * nz - 1 + i] = '0';
			for (int i = 0; i <= c; ++i) ans[2 * nz + a + i] = '1';
		}
		for (int i = 0; i <= a + b + c; ++i) printf("%c", ans[i]);
		printf("\n");
	}
	return 0;
}