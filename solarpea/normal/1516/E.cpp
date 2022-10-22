#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T> void read(T &x){
	x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
}
const int MAXK=200;
const int MOD=1e9+7;
int n,k,dp[MAXK+5][MAXK+5][2*MAXK+5],inv[2*MAXK+5];
int bin[MAXK*2+5][MAXK+5],ans[MAXK+5],fac[MAXK+5];
int binom(int x,int y){
	if(x<y||x<0) return 0;int ret=1;
	for(int i=0;i<y;i++) ret=1ll*ret*(x-i)%MOD;
	for(int i=1;i<=y;i++) ret=1ll*ret*inv[i]%MOD;
	return ret;
}
int main(){
	scanf("%d%d",&n,&k);dp[1][0][0]=1;fac[0]=1;
	for(int i=1;i<=k+1;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	for(int i=(inv[1]=1)+1;i<=(k<<1);i++) inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=0;i<=2*k;i++) for(int j=2;j<=k+1;j++) bin[i][j]=binom(n-i,j);
	for(int i=2;i<=k+1;i++) for(int j=0;j<=k;j++) for(int l=0;l<=2*k;l++){
		if(!dp[i-1][j][l]) continue;int mul=1;
		for(int t=0;j+(i-1)*t<=k;t++){
			dp[i][j+(i-1)*t][l+i*t]=(dp[i][j+(i-1)*t][l+i*t]+1ll*dp[i-1][j][l]*mul)%MOD;
			mul=1ll*mul*bin[l+i*t][i]%MOD*inv[t+1]%MOD*fac[i-1]%MOD;
		}
	}
	for(int j=0;j<=k;j++) for(int l=0;l<=2*k;l++) ans[j]=(ans[j]+dp[k+1][j][l])%MOD;
	for(int j=2;j<=k;j++) ans[j]=(ans[j]+ans[j-2])%MOD;
	for(int j=1;j<=k;j++) printf("%d ",ans[j]);
	return 0;
}