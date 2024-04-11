#include<cstdio>
#include<iostream>
using namespace std;
const int o=6e5,MOD=998244353;
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int n,bt,w[o],rev[o],t1[o],t2[o],dp[o],ans[o],c1,c2,fac[o],inv[o];
inline void init(){
	for(int i=1;i<(1<<bt);++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bt-1));
	w[1<<(bt-1)]=1;
	for(int i=1<<(bt-1),j=qp(3,(MOD-1)/(1<<bt));i<(1<<bt);++i) w[i+1]=w[i]*1ll*j%MOD;
	for(int i=(1<<(bt-1))-1;i;--i) w[i]=w[i<<1];
}
inline void ntt(int*a,int n,bool inv){
	for(int i=1;i<n;++i) if(rev[i]<i) swap(a[rev[i]],a[i]);
	for(int md=1;md<n;md<<=1) for(int i=0;i<n;i+=md<<1) for(int j=0,x,y;j<md;++j)
		x=a[i+j],y=a[i+j+md]*1ll*w[j+md]%MOD,a[i+j]=(x+y)%MOD,a[i+j+md]=(x-y+MOD)%MOD;
	if(inv) for(int i=1,j=n-1;i<j;swap(a[i++],a[j--]));
}
int main(){
	scanf("%d",&n);
	inv[1]=1;for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
	for(int i=fac[0]=t1[0]=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%MOD;
	for(int i=1;i<=n;++i) t1[i]=inv[i]*1ll*t1[i-1]%MOD;
	for(int i=(n-1)/2;i<=n-2;++i) t2[i]=fac[n-2-i];
	c1=n+1;c2=n-1;dp[1]=fac[n-1];
	for(bt=1;(1<<bt)<c1+c2;++bt);
	init();ntt(t1,1<<bt,0);ntt(t2,1<<bt,0);
	for(int i=0;i<(1<<bt);++i) t1[i]=t1[i]*1ll*t2[i]%MOD;
	ntt(t1,1<<bt,1);
	for(int i=0,j=qp(1<<bt,MOD-2);i<(1<<bt);++i) t1[i]=t1[i]*1ll*j%MOD;
	for(int i=2;i<=n;++i) dp[i]=t1[n-i]*(i-1ll)%MOD*fac[n-i]%MOD;
	for(int i=n,s=0;i;s=(s+ans[i--])%MOD) ans[i]=(dp[i]+MOD-s*1ll*inv[i]%MOD)%MOD;
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}