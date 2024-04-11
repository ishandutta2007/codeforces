#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
int a[400010];
int fac[400010],ifac[400010];
const int mod=998244353;
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int C(int x,int y){
	if(x<y) return 0;
	if(x<0||y<0) return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int ans;
int main(){
	n=read();
	for(int i=1;i<=2*n;++i) a[i]=read();
	fac[0]=1;
	for(int i=1;i<=2*n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[2*n]=qpow(fac[2*n],mod-2);
	for(int i=2*n-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	sort(a+1,a+2*n+1);
	int tmp=C(2*n,n);
	for(int i=1;i<=n;++i){
		(ans+=1ll*tmp*a[i+n]%mod)%=mod;
		((ans-=1ll*tmp*a[i]%mod)+=mod)%=mod;
	}
	print((ans+mod)%mod);
}