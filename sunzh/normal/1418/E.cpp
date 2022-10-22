#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
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
int n,m;
int d[200010];
int a[200010],b[200010];
int sum[200010];
const int mod=998244353;
inline int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) d[i]=read();
	for(int i=1;i<=m;++i) a[i]=read(),b[i]=read();
	sort(d+1,d+n+1);
	for(int i=n;i>=1;--i) sum[i]=(sum[i+1]+d[i])%mod;
	for(int i=1;i<=m;++i){
		int j=lower_bound(d+1,d+n+1,b[i])-d;
		int num=n-j+1;
		if(num<a[i]) printf("0\n");
		else printf("%lld\n",(1ll*sum[j]*(1ll*qpow(num,mod-2)%mod*(num-a[i])%mod+mod)%mod
		+1ll*(sum[1]-sum[j])*(1ll*qpow(num+1,mod-2)*(num+1-a[i])%mod+mod)%mod+mod)%mod);
	}
	return 0;
}