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
const int mod=1e9+7;
int n,q;
int fac[3000010],ifac[3000010];
int f[3000010];
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
	n=read(),q=read();
	fac[0]=1;
	for(int i=1;i<=3*n+5;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[3*n+5]=qpow(fac[3*n+5]);
	for(int i=3*n+4;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i){
		++f[0];(f[1]+=i*3)%=mod;
	}
	int iv3=qpow(3);
	for(int i=2;i<=n*3;++i){
		f[i]=1ll*(C(3*n+3,i+1)-C(3,i+1)-3ll*f[i-1]-f[i-2])%mod;
		f[i]=1ll*(f[i]+mod)%mod*iv3%mod;
	}
	// printf("%d\n",f[3*n]);
	while(q--){
		int x=read();printf("%d\n",f[x]);
	}
}