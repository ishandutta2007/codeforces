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
int L[1000010],R[1000010];
int pr[1000010],sf[1000010];
char str[1000010];
int n;
int fac[2000010],ifac[2000010];
const int mod=998244353;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int C(int x,int y){
	if(x<y||x<0||y<0) return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	fac[0]=1;for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n]);
	for(int i=n-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i) L[i]=L[i-1]+(str[i]=='('),pr[i]=pr[i-1]+(str[i]=='?');
	for(int i=n;i>=1;--i) R[i]=R[i+1]+(str[i]==')'),sf[i]=sf[i+1]+(str[i]=='?');
	int ans=0;
	for(int i=1;i<n;++i){
		(ans+=1ll*L[i]*C(pr[i]+sf[i+1],sf[i+1]+R[i+1]-L[i])%mod)%=mod;
		(ans+=1ll*pr[i]*C(pr[i]+sf[i+1]-1,sf[i+1]+R[i+1]-L[i]-1)%mod)%=mod;
	}
	printf("%d\n",ans);
}