#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 505;
int n, a[N][N];

void solve() {
	n = get();
	for(int i = 1; i <= n << 1; i++)
		for(int j = 1; j <= n << 1; j++)
			a[i][j] = get();
	int ans = 0;
	for(int i = n + 1; i <= n << 1; i++)
		for(int j = n + 1; j <= n << 1; j++)
			ans += a[i][j];
	ans += min(min(min(a[1][n + 1], a[1][n * 2]), min(a[n][n + 1], a[n][n * 2])), min(min(a[n + 1][1], a[n + 1][n]), min(a[n * 2][1], a[n * 2][n])));
	cout << ans << endl;
}

main() {
	int T = get();
	while(T--) solve(); 
	return 0;
}