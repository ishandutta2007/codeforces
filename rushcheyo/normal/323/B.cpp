#include <bits/stdc++.h>
using namespace std;

int n, a[1005][1005];

int main() {
	scanf("%d", &n);
	if (n == 4) return puts("-1"), 0;
	if (n % 2 == 0) {
		a[1][2] = a[1][3] = a[1][4] = 1;
		a[2][3] = a[2][4] = a[2][5] = 1;
		a[3][4] = a[3][6] = 1;
		a[4][5] = a[4][6] = 1;
		a[5][1] = a[5][3] = a[5][6] = 1;
		a[6][1] = a[6][2] = 1;
	} else a[1][2] = a[2][3] = a[3][1] = 1;
	for (int i = n % 2 == 0 ? 8 : 5; i <= n; i += 2) {
		for (int j = 1; j <= i - 2; j++) a[j][i - 1] = a[i][j] = 1;
		a[i - 1][i] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			printf("%d%c", a[i][j], " \n"[j == n]);
}