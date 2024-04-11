#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 55
#define now dp[a][b][nxt]
#define val g[p][nxt]

const int mod = 1e9 + 7;

int dp[N][N][N], g[N][N];
int n, d[N], gas[N];

LL piece(int a, int b, int nxt){
	if(a < 0 || b < 0 || nxt < 0) return 0;
	if(~now) return now;
	if(nxt) return now = (a * piece( a - 1, b, nxt - 1) + b * piece( a + 1, b - 1, nxt - 1)) % mod;
	if(a) return now = ((a - 1) * piece(a - 2, b, nxt) + b * piece(a, b - 1, nxt)) % mod;
	if(!b) return now = 1;
	return now = ( (b - 1) * (b - 2) / 2 * piece(a + 2, b - 3, nxt) ) % mod;
}

LL query(int p, int nxt){
	if(p + nxt > n) return 0;
	if(p == n) return nxt == 0;
	if(nxt == 0) return 0;
	int u = gas[p + nxt] - gas[p];
	if(~val) return val;
	val = 0;
	for(int i = 0; i <= n - p - nxt; i ++){
		val = (val + piece(u, nxt - u, i) * query( p + nxt, i)) % mod;
	}
	return val;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", d + i);
		gas[i] = gas[i-1] + (d[i] == 2);
	}
	memset(dp, -1, sizeof dp);
	memset(g, -1, sizeof g);
	cout << query(1, d[1]) << endl;
}