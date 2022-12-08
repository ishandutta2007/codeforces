#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2005;
int n, t;
double p, f[N][N];

//f[i][j]:  i  j  

int main() {
	n = get(), scanf("%lf", &p), t = get();
	f[0][0] = 1; 
	for(int i = 1; i <= t; i++) 
		for(int j = 0; j <= n; j++)
			if(j == 0) f[i][j] = (1 - p) * f[i - 1][j];
			else if(j == n) f[i][j] = f[i - 1][j] + p * f[i - 1][j - 1];
			else f[i][j] = p * f[i - 1][j - 1] + (1 - p) * f[i - 1][j];
	double ans = 0;
	for(int i = 1; i <= n; i++) ans += f[t][i] * i;
	printf("%lf", ans);
	return 0;
}