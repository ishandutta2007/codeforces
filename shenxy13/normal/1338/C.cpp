#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		long long n;
		scanf("%lld", &n);
		long long row = (n - 1) / 3 + 1, h = 1, p4 = 1;
		while (h + p4 <= row) h += p4, p4 *= 4;
		if (n % 3 == 0) {
			long long base = 3 * p4;
			row -= h;
			while (p4 != 1) {
				p4 /= 4;
				if (row / p4 == 1) base += 3 * p4;
				else if (row / p4 == 2) base += p4;
				else if (row / p4 == 3) base += 2 * p4;
				row %= p4;
			}
			printf("%lld\n", base);
		} else if (n % 3 == 2) {
			long long base = 2 * p4;
			row -= h;
			while (p4 != 1) {
				p4 /= 4;
				if (row / p4 == 1) base += 2 * p4;
				else if (row / p4 == 2) base += 3 * p4;
				else if (row / p4 == 3) base += 1 * p4;
				row %= p4;
			}
			printf("%lld\n", base);
		} else printf("%lld\n", p4 + row - h);
	}
	return 0;
}