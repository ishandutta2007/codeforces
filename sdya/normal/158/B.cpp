#include <iostream>
#include <cstdio>

using namespace std;

const int maxN = 10;

int n;
int a[maxN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		++a[x];
	}

	int res = 0, d;
	res += a[3] + a[4];
	a[1] -= a[3];
	if (a[1] < 0) a[1] = 0;
	res += a[2] / 2;
	a[2] %= 2;
	res += a[2];
	a[1] -= a[2] * 2;
	if (a[1] < 0) a[1] = 0;
	res += (a[1] + 3) / 4;
	printf("%d\n", res);

	return 0;
}