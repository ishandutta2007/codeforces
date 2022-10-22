#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int a[5010];
int dp[5010][10010];
int ans[10010];
int inv[5010];
const int mod=1e9+7;
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int main(){
	n=read();
	for(int i=1;i<n;++i) a[i]=read();
	int k=1;
	for(int i=1;i<=n;++i){
		inv[i]=qpow(a[i],mod-2);
		int x=1;
		for(int j=1;j<=2*(n-1);++j){
			x=(i+j>n?0:1ll*x*a[i+j-1]%mod);
			(dp[i][j]+=x)%=mod;
			(ans[j]+=1ll*dp[i][j]*k%mod)%=mod;
			(dp[i+1][j+1]+=1ll*(dp[i][j]-x+mod)%mod+1ll*x*inv[i]%mod*(a[i]-1)%mod)%=mod;
		}
		++dp[i+1][1];
		k=1ll*k*a[i]%mod;
	}
	int inv2=qpow(2,mod-2);
	for(int i=1;i<=2*(n-1);++i) printf("%lld ",1ll*ans[i]*inv2%mod);
}