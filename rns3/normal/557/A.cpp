#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f, x, y, z, n;
    scanf("%d %d %d %d %d %d %d", &n, &a, &b, &c, &d, &e, &f);
    x = min(b, n - c - e);
    y = min(d, n - x - e);
	z = n - x - y;
	printf("%d %d %d\n", x, y, z);
	return 0;
}