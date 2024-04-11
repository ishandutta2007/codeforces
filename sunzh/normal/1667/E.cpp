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
int dp[200010],ans[200010];
const int mod=998244353;
int fac[200010],ifac[200010];
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int C(int x,int y){
	if(x<y) return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
	n=read();
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n]);
	for(int i=n-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	const int B=(n-1>>1);
	for(int i=1;i<=n;++i) dp[i]=1ll*C(n-i,B)*fac[B]%mod*fac[n-B-1]%mod;
	int sum=0;
	for(int i=n;i>=1;--i){
		int res=(dp[i]-1ll*sum*qpow(i)%mod+mod)%mod;
		ans[i]=res;
		(sum+=res)%=mod;
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
}