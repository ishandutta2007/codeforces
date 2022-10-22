#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Step(i, a, b) for (i = a; i <= b; i += 2)
using namespace std;
inline int read() {
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}
int n;
int main() {
	int i;
	cin >> n;
	if (n < 4) return puts("NO"), 0;
	puts("YES");
	if (n & 1) {
		puts("3 * 5 = 15");
		puts("2 * 4 = 8");
		puts("15 + 8 = 23");
		puts("23 + 1 = 24");
		Step (i, 7, n) {
			printf("%d - %d = 1\n", i, i - 1);
			puts("24 * 1 = 24");
		}
	}
	else {
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		Step (i, 6, n) {
			printf("%d - %d = 1\n", i, i - 1);
			puts("24 * 1 = 24");
		}
	}
	return 0;
}