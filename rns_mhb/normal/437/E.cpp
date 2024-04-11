#include <bits/stdc++.h>
using namespace std;
#define N 205
#define ll long long

const int mod = 1e9 + 7;
ll dp[N][N], x[N], y[N], t;

ll f(ll a, ll b, ll c, ll d){
	return a * d - b * c;
}

ll func(int a, int b){
	if(b == a + 1) return dp[a][b] = 1;
	if(dp[a][b] != -1) return dp[a][b];
	dp[a][b] = 0;
	for(int i = a + 1; i < b; i++) if(f(x[b] - x[i], y[b] - y[i], x[a] - x[i], y[a] - y[i]) > 0) dp[a][b] = (func(a, i) * func(i, b) + dp[a][b]) % mod;
	return dp[a][b];
}

int main(){
	int i, n;
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%I64d %I64d", x + i, y + i);
	for(i = 1; i < n; i++) t += f(x[i], y[i], x[i + 1], y[i + 1]);
	t += f(x[n], y[n], x[1], y[1]);
	if(t < 0){
		reverse(x + 1, x + n + 1);
		reverse(y + 1, y + n + 1);
	}
	printf("%I64d", func(1, n));
}