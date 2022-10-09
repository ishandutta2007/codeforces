#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ceil(a, b) (a / b + bool(a % b))

typedef long double ld;
typedef long long int64;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (abs(c - d) > 1) {
		printf("-1");
		return 0;
	}
	if (c == d) {
		if (a < c || b < c || (a == c && b == c)) {
			printf("-1");
			return 0;
		}
		if (a > c) {
			forn (i, a - c) {
				printf("4");
			}
			forn (i, c - 1) {
				printf("74");
			}
			forn (i, b - c + 1) {
				printf("7");
			}
			printf("4");
			return 0;
		}
		forn (i, c) {
			printf("74");
		}
		forn (i, b - c) {
			printf("7");
		}
		return 0;
	}
	if (c > d) {
		if (a < c || b < c) {
			printf("-1");
			return 0;
		}
		forn (i, a - c + 1) {
			printf("4");
		}
		printf("7");
		forn (i, c - 1) {
			printf("47");
		}
		forn (i, b - c) {
			printf("7");
		}
		return 0;
	}
	if (a < d || b < d) {
		printf("-1");
		return 0;
	}
	printf("7");
	forn (i, a - d + 1) {
		printf("4");
	}
	forn (i, d - 2) {
		printf("74");
	}
	forn (i, b - d + 1) {
		printf("7");
	}
	printf("4");
}