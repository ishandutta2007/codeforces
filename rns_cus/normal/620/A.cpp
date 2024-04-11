#include <bits/stdc++.h>
using namespace std;

int x[3], y[3];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d %d %d", &x[1], &y[1], &x[2], &y[2]);
	int dx = abs(x[1] - x[2]), dy = abs(y[1] - y[2]);
	printf("%d\n", max(dx, dy));
	return 0;
}