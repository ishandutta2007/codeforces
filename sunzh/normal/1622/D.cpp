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
int n,k;
char str[200010];
int fac[200010],ifac[200010];
const int mod=998244353;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int p[200010],cnt;
int C(int x,int y){
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
	n=read(),k=read();
	if(k==0){
		printf("1\n");return 0;
	}
	scanf("%s",str+1);
	for(int i=1;i<=n;++i){
		if(str[i]=='1') p[++cnt]=i;
	}
	if(k>cnt){
		printf("1\n");return 0;
	}
	int ans=0;
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n]);
	for(int i=n-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	p[cnt+1]=n+1;
	for(int i=1;i+k-1<=cnt;++i){
		int len=p[i+k]-1-p[i-1];
		(ans+=C(len,k))%=mod;
	}
	for(int i=2;i+k-1<=cnt;++i){
		int len=p[i+k-1]-1-p[i-1];
		(ans-=C(len,k-1))%=mod;
	}
	printf("%d\n",(ans+mod)%mod);
}