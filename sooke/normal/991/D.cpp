#include <cstdio>
#include <iostream>
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Inf 1000000000

using namespace std;

int n, f[5][105];
string u, d;

int main() {
	cin >> u >> d;
	n = u.size();
	u = " " + u;
	d = " " + d;
	if (n <= 1) {
		printf("0\n");
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (u[i] == '0' && d[i - 1] == '0' && d[i] == '0') {
			f[1][i] = Max(f[0][i - 1], f[3][i - 1]) + 1;
		}
		if (u[i - 1] == '0' && d[i - 1] == '0' && d[i] == '0') {
			f[2][i] = f[0][i - 1] + 1;
		}
		if (u[i - 1] == '0' && u[i] == '0' && d[i - 1] == '0') {
			f[3][i] = f[0][i - 1] + 1;
		}
		if (u[i - 1] == '0' && u[i] == '0' && d[i] == '0') {
			f[4][i] = Max(f[0][i - 1], f[2][i - 1]) + 1;
		}
		f[0][i] = Max(Max(f[1][i - 1], f[2][i - 1]), Max(f[3][i - 1], f[4][i - 1]));
		f[0][i] = Max(f[0][i], f[0][i - 1]);
	}
	printf("%d\n", Max(f[0][n], Max(Max(f[1][n], f[2][n]), Max(f[3][n], f[4][n]))));
	return 0;
}

// By Sooke.