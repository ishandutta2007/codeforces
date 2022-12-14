#include <bits/stdc++.h>
using namespace std;
#define M 100100
int ABS(int u) {return u < 0 ? -u : u;}

int x, y, X, Y;

int main() {
	scanf("%d %d %d %d", &x, &y, &X, &Y);
	printf("%d\n", max(ABS(x-X), ABS(y-Y)));

	return 0;
}