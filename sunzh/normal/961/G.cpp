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
int k,n;
int w[200010];
const int mod=1e9+7;
int fac[200010],ifac[200010];
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int main(){
	n=read(),k=read();
	if(n==1){
		printf("%d\n",read());return 0;
	}
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n]);
	for(int i=n-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i) w[i]=read();
	int S=0;
	for(int j=0;j<=k-1;++j){
		int t=(((k-j-1)&1)?mod-1:1);
		t=1ll*t*ifac[j]%mod*ifac[k-1-j]%mod*(qpow(j+1,n-1)+1ll*(n-1)*qpow(j+1,n-2)%mod)%mod;
		(S+=t)%=mod;
	}
	// printf("S:%d\n",S);
	int ans=0;
	for(int i=1;i<=n;++i) (ans+=1ll*S*w[i]%mod)%=mod;
	printf("%d\n",ans);
}