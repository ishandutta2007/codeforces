#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105, M = 10005;
int n, x, c[N], s;
double p[N][M], f[N];

int main() {
	n = get(), x = get();
	for(int i = 1; i <= n; i++) c[i] = get(), s += c[i]; 
	f[0] = x;
	for(int i = 1; i < n; i++) f[i] = x / 2.0 * (1.0 * n / (n - i) - 1) + x;
	p[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = i - 1; j >= 0; j--)
			for(int k = s - c[i]; k >= 0; k--)
				p[j + 1][k + c[i]] += p[j][k] * (j + 1) / (n - j);
	double ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= s; j++)
			ans += p[i][j] * min(f[i], 1.0 * (s - j) / (n - i));
	printf("%.10lf", ans);
	return 0;
}