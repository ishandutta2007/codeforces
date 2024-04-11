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
	int n;
	cin >> n;
	if (n & 1) {
		forn (i, n / 2) {
			if (i & 1) {
				printf("aa");
			} else {
				printf("bb");
			}
		}
		printf("c\n");
		forn (i, n / 2) {
			if (i & 1) {
				printf("dd");
			} else {
				printf("ee");
			}
		}
		printf("c\n");
		printf("f");
		forn (i, n / 2) {
			if (i & 1) {
				printf("gg");
			} else {
				printf("hh");
			}
		}
		printf("\nf");
		forn (i, n / 2) {
			if (i & 1) {
				printf("ii");
			} else {
				printf("jj");
			}
		}
	} else {
		printf("c");
		forn (i, n / 2 - 1) {
			if (i & 1) {
				printf("aa");
			} else {
				printf("bb");
			}
		}
		printf("f\nc");
		forn (i, n / 2 - 1) {
			if (i & 1) {
				printf("dd");
			} else {
				printf("ee");
			}
		}
		printf("f\n");
		forn (i, n / 2) {
			if (i & 1) {
				printf("gg");
			} else {
				printf("hh");
			}
		}
		printf("\n");
		forn (i, n / 2) {
			if (i & 1) {
				printf("ii");
			} else {
				printf("jj");
			}
		}
	}
}