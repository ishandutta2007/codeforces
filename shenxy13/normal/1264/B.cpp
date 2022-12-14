#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (b < a) {
		if (c != 0 || d != 0) printf("NO");
		else {
			if (abs(a - b) > 1) printf("NO");
			else {
				printf("YES\n");
				if (a < b) {
					for (int i = 0; i < a; ++i) printf("1 0 ");
					printf("1 ");
				} else if (a > b) {
					for (int i = 0; i < b; ++i) printf("0 1 ");
					printf("0 ");
				} else {
					for (int i = 0; i < a; ++i) printf("0 1 ");
				}
			}
		}
	} else if (c < d) {
		if (a != 0 || b != 0) printf("NO");
		else {
			if (abs(c - d) > 1) printf("NO");
			else {
				printf("YES\n");
				if (c < d) {
					for (int i = 0; i < c; ++i) printf("3 2 ");
					printf("3 ");
				} else if (c > d) {
					for (int i = 0; i < d; ++i) printf("2 3 ");
					printf("2 ");
				} else {
					for (int i = 0; i < c; ++i) printf("2 3 ");
				}
			}
		}
	} else if (abs((b - a) - (c - d)) > 1) printf("NO");
	else {
		printf("YES\n");
		if (b - a == c - d) {
			for (int i = 0; i < a; ++i) printf("0 1 ");
			for (int i = 0; i < b - a; ++i) printf("2 1 ");
			for (int i = 0; i < d; ++i) printf("2 3 ");
		} else if (b - a > c - d) {
			for (int i = 0; i < a; ++i) printf("1 0 ");
			printf("1 ");
			for (int i = 0; i < c - d; ++i) printf("2 1 ");
			for (int i = 0; i < d; ++i) printf("2 3 ");
		} else {
			for (int i = 0; i < a; ++i) printf("0 1 ");
			for (int i = 0; i < b - a; ++i) printf("2 1 ");
			printf("2 ");
			for (int i = 0; i < d; ++i) printf("3 2 ");
		}
	}
	return 0;
}