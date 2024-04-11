#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e3 + 5;
int n, q, A[N];
double f[N][N]; 

signed main() {
	n = get(), q = get();
	for(int i = 1; i <= n; i++) A[i] = get();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			f[i][j] = A[i] > A[j];
	for(int t = 1; t <= q; t++) {
		int x = get(), y = get();
		f[x][y] = f[y][x] = (f[x][y] + f[y][x]) / 2;
		for(int i = 1; i <= n; i++) {
			if(i == x || i == y) continue;
			f[i][x] = f[i][y] = (f[i][x] + f[i][y]) / 2;
			f[x][i] = f[y][i] = (f[x][i] + f[y][i]) / 2;
		} 
	} 
	double ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			ans = ans + f[i][j];
	printf("%.9lf", ans);
	return 0;
}