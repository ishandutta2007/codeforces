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
int n,mod;
int fac[100010],ifac[100010];
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int C(int x,int y){
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int pw[5010][5010];
int main(){
	n=read(),mod=read();
	pw[0][0]=1;
	for(int i=1;i<=5000;++i){
		pw[i][0]=1;
		for(int j=1;j<=5000;++j) pw[i][j]=1ll*pw[i][j-1]*i%mod;
	}
	fac[0]=1;
	for(int i=1;i<=100000;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[100000]=qpow(fac[100000]);
	for(int i=99999;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	int ans=0;
	for(int x=0;x*2<=n;++x){
		for(int y=0;y+x+x<=n;++y){
			int res=1ll*pw[n-x-y][y]*pw[n-1][x]%mod;
			res=1ll*res*fac[n]%mod*ifac[x]%mod*ifac[y]%mod;
			res=1ll*res*C(n-x-y-1,x-1)%mod;
			(ans+=res)%=mod;
			//C(n,x)*C(n-x,x)*C(n-x-x,y) x! (n-2x-y)!
		}
	}
	printf("%d\n",ans);
}