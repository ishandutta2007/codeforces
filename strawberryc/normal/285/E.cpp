#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
using namespace std;

const int N = 1005, ZZQ = 1e9 + 7;
int n, m, fac[N], C[N][N], f[N][N][2][2][2], ans;

int main()
{
	int i, j, op1, op2, op3;
	cin >> n >> m;
	fac[0] = 1;
	For (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % ZZQ;
	For (i, 0, n) C[i][0] = 1;
	For (i, 1, n) For (j, 1, i)
		C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % ZZQ;
	f[0][0][0][0][0] = 1;
	For (i, 0, n - 1) For (j, 0, i)
	{
		For (op1, 0, 1) For (op2, 0, 1) For (op3, 0, 1)
			(f[i + 1][j][op2][op3][0] += f[i][j][op1][op2][op3]) %= ZZQ;
		if (i > 0) For (op1, 0, 1) For (op3, 0, 1)
			(f[i + 1][j + 1][1][op3][0] += f[i][j][op1][0][op3]) %= ZZQ;
		if (i < n - 1) For (op1, 0, 1) For (op2, 0, 1) For (op3, 0, 1)
			(f[i + 1][j + 1][op2][op3][1] += f[i][j][op1][op2][op3]) %= ZZQ;
	}
	For (i, m, n)
	{
		int tmp = 0;
		For (op1, 0, 1) For (op2, 0, 1)
			tmp = (tmp + f[n][i][op1][op2][0]) % ZZQ;
		int delta = 1ll * tmp * fac[n - i] % ZZQ * C[i][m] % ZZQ;
		if (i - m & 1) ans = (ans - delta + ZZQ) % ZZQ;
		else ans = (ans + delta) % ZZQ;
	}
	cout << ans << endl;
	return 0;
}