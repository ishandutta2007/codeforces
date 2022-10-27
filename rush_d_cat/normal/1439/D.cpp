#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 10;
int n,m,p;
LL c[N][N],f[N],g[N];
LL dp[N][N], ways[N][N];
LL dp2[N][N], ways2[N][N];
LL dp0[N][N], ways0[N][N];
void add(LL &x,LL y){
	x=(x+y)%p;
}
LL cal(LL x){
	return 1LL*x*(x-1)/2 % p; 
}
int main() {
    cin>>n>>m>>p;
    for(int i=0;i<N;i++)c[i][0]=1;
    for(int i=1;i<N;i++){
    	for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
    }
	f[0]=0; g[0]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){
			LL add1 = c[i-1][j-1] * f[j-1] % p * g[i-j] % p * (i+1) % p;
			LL add2 = c[i-1][j-1] * g[j-1] % p * f[i-j] % p * (i+1) % p;
			add(f[i], add1 + add2 + (c[i-1][j-1] * g[j-1] % p * g[i-j] % p) * ((cal(j) + cal(i-j+1)) % p) % p);
			add(g[i], c[i-1][j-1] * g[j-1] % p * g[i-j] % p * (i+1) % p);
		}
		//printf("f[%d] = %lld %lld\n", i, f[i], g[i]);
	}
	dp[0][0]=0;ways[0][0]=1;
	for(int i=0;i<n;i++){ 
		memset(dp2,0,sizeof(dp2));
		memset(ways2,0,sizeof(ways2));
		for(int j=0;j<=min(i,m);j++){
			for(int k=0;k<=min(j,m);k++){
				if(k==0){
					dp0[i][j] = dp[j][0]; ways0[i][j]=ways[j][0];
				}
				//printf("dp[%d][%d][%d] = %lld, %lld\n", i,j,k,ways[j][k],dp[j][k]);
				add(dp2[j][0],dp[j][k]);
				add(ways2[j][0], ways[j][k]);
				int rem=m-(j-k);
				add(ways2[j+1][k+1],1LL * ways0[i-k][j-k] * c[rem][k+1] % p * g[k+1] % p);
				add(dp2[j+1][k+1], 1LL * dp0[i-k][j-k] * c[rem][k+1] % p * g[k+1] % p + 1LL * ways0[i-k][j-k] * c[rem][k+1] % p * f[k+1] % p);
			}
		}
		for(int j=0;j<N;j++)for(int k=0;k<N;k++){
			dp[j][k]=dp2[j][k], ways[j][k]=ways2[j][k];
		}
	}
	LL ans=0;
	for(int i=0;i<=m;i++)
		add(ans, dp[m][i]);
	cout<<ans<<endl;
}