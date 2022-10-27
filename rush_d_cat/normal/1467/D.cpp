#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000 + 10;
const ll mod = 1e9 + 7;
int n, k, q;
int a[N];
ll dp[N][N];
ll cof[N];

int main() {

	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);

	for(int i=1;i<=n;i++) dp[i][0]=1;
	for(int i=1;i<=k;i++){
		for(int x=1;x<=n;x++){
			dp[x][i]=(dp[x-1][i-1] + dp[x+1][i-1])%mod;
		}
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++)
			cof[i] = (cof[i] + dp[i][j] * dp[i][k-j] % mod) % mod;
		sum = sum + cof[i] * a[i] % mod;
		sum %= mod;
	}
	while(q--) {
		int x, y; scanf("%d%d",&x,&y);
		sum -= cof[x] * a[x];
		a[x] = y;
		sum += cof[x] * a[x];

		sum = (sum % mod + mod) % mod;
		printf("%lld\n", sum);
	}

}