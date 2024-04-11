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
int n;
int mod;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int ifac[210],fac[210];
int dp[210][210][210];
void addx(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
int solve(int X){
	memset(dp,0,sizeof(dp));
	dp[X-1][0][0]=1;
	for(int i=X;i<=n+1;++i){
		for(int j=0;j<=n;++j){
			for(int k=0;k<=n;++k) if(dp[i-1][j][k]){
				int ls=(i==X||i==n+1);
				for(int t=ls;t+j<=n;++t){
					if(k+(i-X)*t>X) break ;
					// printf("t:%d\n",t);
					if(!(i==X?t+j<=X:t+j<i)) break ;
					// printf("i:%d,j:%d,k:%d,t:%d\n",i,j,k,t);
					addx(dp[i][j+t][k+(i-X)*t],1ll*dp[i-1][j][k]*ifac[t]%mod);
				}
			}
		}
	}
	int res=0;
	for(int i=0;i<=X;++i) addx(res,dp[n+1][n][i]);
	// printf("X:%d,%d\n",X,1ll*fac[n]*res%mod);
	return 1ll*fac[n]*res%mod;
}
int main(){
	n=read(),mod=read();
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n]);
	int ans=1;
	for(int i=n-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=max(1,n-32);i<=n+1;++i) (ans+=solve(i))%=mod;
	printf("%d\n",ans);
}