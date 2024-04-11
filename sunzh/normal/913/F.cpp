#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int dp[2010][2010];
int f[2010];
int g[2010],h[2010];
int n;
int p;
const int mod=998244353;
inline int qpow(int x,int k){
	int res=1;
//	printf("x:%d,k:%d\n",x,k);
	while(k){
//		printf("k:%d\n",k);
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int main(){
	n=read();
	int a=read(),b=read();p=1ll*a*qpow(b,mod-2)%mod;
	for(int i=0;i<=n;++i) dp[i][0]=1;f[0]=1;
	for(int i=1;i<=n;++i){
		f[i]=1;
		for(int j=1;j<i;++j){
			dp[i][j]=(1ll*dp[i-1][j-1]*qpow(1-p+mod,i-j)%mod+1ll*dp[i-1][j]*qpow(p,j)%mod)%mod;
			f[i]=(f[i]-1ll*dp[i][j]*f[j]%mod+mod)%mod;
		}
		dp[i][i]=1;
	}
	for(int i=1;i<=n;++i){
		int s=1ll*i*(i-1)>>1;
		for(int j=1;j<i;++j){
			s=(s+1ll*dp[i][j]*f[j]%mod*(g[j]+h[i-j])%mod)%mod;
		}
		g[i]=1ll*qpow(1-f[i]+mod,mod-2)*s%mod;
		h[i]=(g[i]-(1ll*i*(i-1)>>1)%mod+mod)%mod;
	}
	printf("%d\n",g[n]);
	return 0;
}