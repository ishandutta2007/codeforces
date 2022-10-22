#include<cstdio>
#include<iostream>
using namespace std;
const int o=6e5,MOD=998244353;
inline int fix(int x){return x+(x>>31&MOD);}
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int n,k,f,g[20][o],rev[o],w[o],a[o],bt;
inline void init(){
	for(int i=1;i<(1<<bt);++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bt-1));
	w[1<<(bt-1)]=1;
	for(int i=(1<<(bt-1)),j=qp(3,(MOD-1)/(1<<bt));i<(1<<bt);++i) w[i+1]=w[i]*1ll*j%MOD;
	for(int i=(1<<(bt-1));--i;) w[i]=w[i<<1];
}
inline void ntt(int*a,int n,bool inv){
	for(int i=1;i<n;++i) if(rev[i]<i) swap(a[rev[i]],a[i]);
	for(int md=1;md<n;md<<=1) for(int i=0;i<n;i+=md<<1) for(int j=0,x,y;j<md;++j)
		x=a[i+j],y=a[i+j+md]*1ll*w[j+md]%MOD,a[i+j]=fix(x+y-MOD),a[i+j+md]=fix(x-y);
	if(inv) for(int i=1,j=(1<<bt)-1;i<j;swap(a[i++],a[j--]));
}
int main(){
	scanf("%d%d%d",&n,&k,&f);
	for(bt=1;(1<<bt)<=2*k;++bt);
	init();
	for(int i=0;i<=k;++i) g[0][i]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<(1<<bt);++j) a[j]=0;
		for(int j=0;j<=k;++j) a[j]=g[i-1][j];
		ntt(a,1<<bt,0);
		for(int j=0;j<(1<<bt);++j) a[j]=a[j]*1ll*a[j]%MOD;
		ntt(a,1<<bt,1);
		for(int j=0,coef=qp(1<<bt,MOD-2);j<(1<<bt);++j) a[j]=a[j]*1ll*coef%MOD;
		for(int j=0;j<=k;++j) g[i][j]=a[j]*1ll*(k-j)%MOD;
		for(int j=2*k;j;--j) a[j-1]=fix(a[j-1]+a[j]-MOD);
		for(int j=0;j<=k;++j) g[i][j]=fix(g[i][j]+a[j]-MOD);
	}
	printf("%d",fix(a[f]-a[f+1]));
	return 0;
}