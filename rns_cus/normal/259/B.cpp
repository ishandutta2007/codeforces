#include <bits/stdc++.h>
using namespace std;

int a[4][4];

int main() {
//	freopen("b.in", "r", stdin);
	for (int i = 1; i <= 3; i ++) for (int j = 1; j <= 3; j ++) scanf("%d", &a[i][j]);
	a[1][1] = max(1, max(a[3][2] - a[1][3] + 1, a[2][3] - a[1][2] + 1));
	a[2][2] = a[1][1] + a[1][3] - a[3][2];
	a[3][3] = a[1][1] + a[1][2] - a[2][3];
	int x = a[3][1] + a[1][3] - a[1][1] - a[3][3];
	x /= 2;
	for (int i = 1; i <= 3; i ++) a[i][i] += x;
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}