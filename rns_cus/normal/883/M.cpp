#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int rlt = abs(a - c) + abs(b - d);
	rlt <<= 1;
	if (a != c && b != d) rlt += 4;
	else rlt += 6;
	printf("%d\n", rlt);

	return 0;
}