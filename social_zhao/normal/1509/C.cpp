#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2005;
int n;
int a[N], f[N][N];

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int i = n; i >= 1; i--)
		for(int j = i + 1; j <= n; j++)
			f[i][j] = a[j] - a[i] + min(f[i + 1][j], f[i][j - 1]);
	printf("%lld\n", f[1][n]);
	return 0;
}