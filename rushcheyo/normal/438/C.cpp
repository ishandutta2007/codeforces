#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int n, x[205], y[205], f[205][205];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", x + i, y + i);
	long long tmp = 0;
	for (int i = 0; i < n; i++) tmp += 1ll * x[i] * y[(i + 1) % n] - 1ll * y[i] * x[(i + 1) % n];
	if (tmp < 0) reverse(x, x + n), reverse(y, y + n);
	for (int i = 0; i < n - 1; i++) f[i][i + 1] = 1;
	for (int i = n - 3; i >= 0; i--)
		for (int j = i + 2; j < n; j++)
			for (int k = i + 1; k < j; k++)
				if (1ll * (x[i] - x[k]) * (y[j] - y[k]) < 1ll * (y[i] - y[k]) * (x[j] - x[k]))
					f[i][j] = (f[i][j] + 1ll * f[i][k] * f[k][j]) % P;
	printf("%d\n", f[0][n - 1]);
	return 0;
}