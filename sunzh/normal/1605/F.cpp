#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,k;
int mod;
int dp[81][81],f[81][81],g[81][81];
int C[81][81];
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int pw[100010];
int main(){
	pw[0]=1;
	n=read(),k=read();
	mod=read();
	for(int i=1;i<=100000;++i) pw[i]=(pw[i-1]<<1)%mod;
	C[0][0]=1;
	for(int i=1;i<=max(n,k);++i){
		for(int j=1;j<i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
		C[i][0]=C[i][i]=1;
	}
	for(int i=0;i<=k;++i) f[1][i]=g[1][i]=1;f[1][0]=0;
	for(int i=2;i<=n;++i){
		for(int j=0;j<=k;++j){
			for(int t=j;t>=0;--t){
				(g[i][j]+=1ll*g[i-1][t]*C[j][t]%mod*pw[t]%mod)%=mod;
				(f[i][j]+=1ll*f[i-1][t]*C[j][t]%mod*((t==j?(pw[j]-i):pw[t]))%mod)%=mod;
			}
			// printf("i:%d,j:%d,f:%d,g:%d\n",i,j,f[i][j],g[i][j]);
		}
	}
	g[0][0]=f[0][0]=1;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=k;++j){
			for(int t=i-1-(i==n?(n&1):0);t>=0;--t){
				for(int q=j-1;q>=0;--q){
					(dp[i][j]+=1ll*(g[t][q]-dp[t][q]+mod)%mod*f[i-t][j-q]%mod*C[i][t]%mod*C[j][q]%mod*pw[q*(i-t)]%mod)%=mod;
				}
			}
			// printf("i:%d,j:%d,%d\n",i,j,dp[i][j]);
		}
	}
	int ans=0;
	for(int i=0;i<=k;++i) (ans+=1ll*(g[n][i]-dp[n][i]+mod)%mod*C[k][i]%mod)%=mod;
	printf("%d\n",ans);
	// printf("%d\n",g[n][k]);
	// printf("%d\n",(g[n][k]-dp[n][k]+mod)%mod);
}