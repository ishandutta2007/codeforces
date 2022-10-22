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
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int mod;
int n=18;
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
void FWT(std::vector<int>&s,int op){
	for(int i=1;i<(1<<n);i<<=1)
		for(int p=i<<1,j=0;j<(1<<n);j+=p)
			for(int k=0;k<i;++k)
				if(op==1) s[i+j+k]=add(s[j+k],s[i+j+k]);
				else s[i+j+k]=add(s[i+j+k]-s[j+k],mod);
}
int N,K;
int fac[1<<18+1],ifac[1<<18+1];
int main(){
	N=read(),K=read(),mod=read();
	if(N&1){
		printf("%d\n",qpow(K,N));
		return 0;
	}
	int x=N;n=0;
	while(x) ++n,x>>=1;
	fac[0]=1;
	for(int i=1;i<=(1<<n);++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[1<<n]=qpow(fac[1<<n],mod-2);
	for(int i=(1<<n)-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	std::vector<int>a[n+1],trans[n+1];
	for(int i=0;i<=n;++i) a[i].resize(1<<n|1),trans[i].resize(1<<n|1);
	for(int i=0;i<=N;++i) trans[__builtin_popcount(i)][i]=ifac[i];
	for(int i=0;i<=n;++i) FWT(trans[i],1);
	a[0][0]=1;
	FWT(a[0],1);
	int t=K;
	while(K){
		if(K&1){
			for(int i=n;i>=0;--i){
				for(int j=0;j<i;++j){
					for(int k=0;k<(1<<n);++k) a[i][k]=add(1ll*a[j][k]*trans[i-j][k]%mod,a[i][k]);
				}
			}
		}
		for(int i=n;i>=0;--i){
			for(int j=0;j<i;++j){
				for(int k=0;k<(1<<n);++k) trans[i][k]=add(1ll*trans[j][k]*trans[i-j][k]%mod,trans[i][k]);
			}
		}
		K>>=1;
	}
	K=t;
	FWT(a[__builtin_popcount(N)],-1);
	printf("%d\n",(qpow(K,N)-1ll*a[__builtin_popcount(N)][N]*fac[N]%mod+mod)%mod);
}