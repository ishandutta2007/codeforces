#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define int long long
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
int n,m,a,b;
const int mod=1e9+7;
int fac[1000010],ifac[1000010];
const int M=1e6;
inline int qpow(int x,int k){
	int res=1ll;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int ans;
int A(int x,int y){
	return 1ll*fac[x]*ifac[x-y]%mod;
}
int C(int x,int y){
	if(x==0&&y==0) return 1;
	if(x-y<0) return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
signed main(){
	n=read(),m=read(),a=read(),b=read();
	fac[1]=1;
	for(int i=2;i<=M;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[M]=qpow(fac[M],mod-2);
	for(int i=M-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	if(n==2){
		puts("1");return 0;
	}
	int invm=qpow(m,mod-2),invn=qpow(n,mod-2);
	int tmp=qpow(m,n-2),tp=qpow(n,n-3);
	for(int i=0;i<=n-2;++i){
//		printf("i:%d\n",i);
		(ans+=1ll*A(n-2,i)*tmp%mod*(i+2)%mod*tp%mod*C(m-1,i)%mod)%=mod;
		tmp=1ll*tmp*invm%mod;tp=1ll*tp*invn%mod;
	}
	print(ans);
}