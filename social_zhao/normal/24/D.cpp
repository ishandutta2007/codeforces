#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e3 + 5;
int n, m, x, y; 
double f[N][N], a[N], b[N];

int main() {
	n = get(), m = get(), x = get(), y = get();
	for(int i = n - 1; i >= 1; i--) {
		if(m == 1) { f[i][1] = f[i + 1][1] + 2; continue; }
		for(int j = 1; j <= m; j++) a[j] = b[j] = 0;
		a[m] = 0.5, b[m] = (f[i + 1][m] + 3) * 0.5;
		for(int j = m - 1; j >= 1; j--) {
			int d = (j == 1)? 3 : 4;
			a[j] = 1.0 / (d - 1 - a[j + 1]);
			b[j] = 1.0 * (b[j + 1] + f[i + 1][j] + d) / (d - 1 - a[j + 1]);
		}
		f[i][1] = b[1];
		for(int j = 2; j <= m; j++) f[i][j] = a[j] * f[i][j - 1] + b[j];
	}
	printf("%.10lf", f[x][y]);
	return 0;
}