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
int b[2010];
int dp[2][110][2010];
int D[5310];
int fac[4010],ifac[4010];
const int mod=998244353;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) b[i]=read();
	dp[0][k][0]=1;bool fl=0;
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n]);
	for(int i=n-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;	
	for(int i=1;i<=n;++i){
		fl^=1;memset(dp[fl],0,sizeof(dp[fl]));
		memset(D,0,sizeof(D));
		int it=-min(k,b[i-1]);
		for(int j=-min(b[i],k);j<=k;++j){
			int val=b[i]+j;
			while(it<val-b[i-1]&&it<=k){
				for(int l=0;l<=i;++l) (D[l+b[i-1]+it]+=1ll*dp[fl^1][it+k][l]*fac[l]%mod)%=mod;
				++it;
			}
			for(int l=0;l<=i;++l){
				if(l+val>0) dp[fl][j+k][l]=1ll*D[l+val-1]*ifac[l]%mod;
				if(abs(val-b[i-1])<=k){
					(dp[fl][j+k][l]+=1ll*(val+l)*dp[fl^1][k+val-b[i-1]][l]%mod)%=mod;
					if(l) (dp[fl][j+k][l]+=dp[fl^1][k+val-b[i-1]][l-1])%=mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=-min(b[n],k);i<=k&&i+b[n]<=n;++i){
		for(int l=0;l<=n&&b[n]+i+l<=n;++l){
			// printf("i:%d,l:%d %d\n",i,l,dp[fl][i][l]);
			(ans+=1ll*dp[fl][i+k][l]*fac[n-(b[n]+i)]%mod*ifac[n-(b[n]+i+l)]%mod)%=mod;
		}
	}
	printf("%d\n",ans);
}///