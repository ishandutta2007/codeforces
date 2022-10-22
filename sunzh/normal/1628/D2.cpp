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
int fac[1000010],ifac[1000010];
// int dp[2010][2010];
int T;
int n,m,k;
const int mod=1e9+7;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
void init(int x){
	fac[0]=1;
	for(int i=1;i<=x;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[x]=qpow(fac[x]);
	for(int i=x-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}
int C(int x,int y){return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;};
int main(){
	T=read();
	init(1000000);
	// for(int i=0;i<=2000;++i) dp[i][0]=0,dp[i][i]=i;
	// for(int i=1;i<=2000;++i){
	// 	for(int j=1;j<i;++j){
	// 		dp[i][j]=1ll*(dp[i-1][j-1]+dp[i-1][j])*(mod+1>>1)%mod;
	// 	}
	// }
	while(T--){
		n=read(),m=read(),k=read();
		int ans=0;
		for(int i=1;i<=n&&i<=m;++i){
			(ans+=1ll*C(n-i,m-i)*qpow((mod+1>>1),n-i)%mod*(i-1ll*(i-1)*(mod+1>>1)%mod+mod)%mod)%=mod;
		}
		printf("%d\n",1ll*ans*k%mod);
		// printf("%d\n",1ll*C(n,m)*k%mod*qpow((mod+1>>1),n)%mod);
	}
}