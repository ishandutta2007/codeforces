#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int a[12] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};

int main() {
	scanf("%d", &n);
	if (n < 12) {
		printf("%d\n", a[n]);
	} else {
		printf("%I64d\n", 292LL + 49LL * (n - 11));
	}
	return 0;
}