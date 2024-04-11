#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		if (n % 10 == 0) {
			n /= 10;
		} else {
			n--;
		}
	}
	printf("%d\n", n);
	return 0;
}

// By Sooke.
// CF977A Wrong Subtraction.