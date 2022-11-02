#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
unsigned xor128() {
	static unsigned x = 123456789;
	static unsigned y = 362436069;
	static unsigned z = 521288629;
	static unsigned w = 88675111;
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
	return w;
}
int n, a[100009], b[100009]; bool ok[100009]; long long sa, sb;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), sa += a[i];
	for (int i = 0; i < n; i++) scanf("%d", &b[i]), sb += b[i];
	while (true) {
		fill(ok, ok + n, false);
		long long ta = 0, tb = 0;
		for (int i = 0; i < n / 2 + 1; i++) {
			int z = xor128() % n;
			while (ok[z]) z = xor128() % n;
			ok[z] = true;
			ta += a[z];
			tb += b[z];
		}
		if (2 * ta > sa && 2 * tb > sb) {
			printf("%d\n", n / 2 + 1);
			int c = 0;
			for (int i = 0; i < n; i++) {
				if (ok[i]) {
					if (c++) printf(" ");
					printf("%d", i + 1);
				}
			}
			printf("\n");
			break;
		}
	}
	return 0;
}