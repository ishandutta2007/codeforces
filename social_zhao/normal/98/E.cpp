#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n, m; 
double dp[1005][1005];

double f(int x, int y) {
	if(x == 0) return dp[x][y] = 1.0 / (y + 1);
	if(y == 0) return 1;
	if(dp[x][y]) return dp[x][y];
	double  A = 1.0 * y / (y + 1) * (1 - f(y - 1, x)), 
			B = 1.0 / (y + 1) + 1.0 * y / (y + 1) * (1 - f(y - 1, x)), 
			C = 1, 
			D = 1 - f(y, x - 1); 
	double p = 1.0 * (D - C) / (A - B - C + D);
	return dp[x][y] = p * A + (1 - p) * C; 
}

int main() {
	n = get(), m = get();
	double ans = f(n, m);
	printf("%.9lf %.9lf", ans, 1 - ans);
	return 0;
}