#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 705;
int n, a[N];
bool cop[N][N], f[N][N][2];

int gcd(int x, int y) { return y? gcd(y, x % y) : x; }

int main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	a[0] = a[n + 1] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cop[i][j] = gcd(a[i], a[j]) == 1;
	for(int i = 1; i <= n; i++) f[i][i][0] = f[i][i][1] = 1;
	for(int l = n; l >= 1; l--)
		for(int r = l; r <= n; r++) 
			for(int k = l; k <= r; k++) 
				if(f[l][k][1] && f[k][r][0]) 
					f[l - 1][r][0] |= !cop[k][l - 1], f[l][r + 1][1] |= !cop[k][r + 1];
	printf((f[1][n][0] || f[1][n][1])? "Yes" : "No");
	return 0;
}