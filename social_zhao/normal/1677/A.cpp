#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5005;
int n, sum[N][N], p[N];

int GetSum(int d, int u, int l, int r) {
	if(d > u || l > r) return 0;
	return sum[u][r] - sum[d - 1][r] - sum[u][l - 1] + sum[d - 1][l - 1];
}

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) p[i] = get();
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++)
			sum[i][j] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(p[i] > p[j]) ++sum[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(p[i] < p[j]) ans += GetSum(i + 1, j - 1, j + 1, n);
	cout << ans << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}