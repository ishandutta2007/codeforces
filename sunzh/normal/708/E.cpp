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
int n,m,k;
const int mod=1e9+7;
int P[100010];
int fac[100010],ifac[100010];
int C(int x,int y){
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int L[1510][1510];
int pr[100010],pr2[100010];
int p;
void prework(){
	fac[0]=1;for(int i=1;i<=k;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[k]=qpow(fac[k]);
	for(int i=k-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=0;i<=k;++i){
		P[i]=1ll*C(k,i)*qpow(p,i)%mod*qpow(1-p+mod,k-i)%mod;
		pr2[i+1]=(pr2[i]+P[i])%mod;
	}
	for(int i=k+2;i<=m;++i) pr2[i]=pr2[i-1];
}
void solve(){
	for(int i=1;i<=m;++i){
		for(int j=i;j<=m;++j){
			(L[1][j]+=1ll*P[i-1]*P[m-j]%mod)%=mod;
		}
	}
	for(int i=1;i<=m;++i){
		(L[1][i]+=L[1][i-1])%=mod;
		// printf("%d ",L[1][i]);
	}
	// printf("\n");
	for(int i=2;i<=n;++i){
		for(int j=1;j<=m;++j){
			pr[j]=(pr[j-1]+1ll*P[j-1]*L[i-1][j-1])%mod;
		}
		for(int j=1;j<=m;++j){
			// printf("j:%d,pr2:%d,pr:%d,P:%d,L:%d %d\n",j,pr2[j],pr[j],P[m-j],L[i-1][m],L[i-1][m-j]);
			L[i][j]=(L[i][j-1]+1ll*P[m-j]*pr2[j]%mod*(L[i-1][m]-L[i-1][m-j])%mod-1ll*P[m-j]*pr[j]%mod)%mod;
		}
	}
}
int main(){
	n=read(),m=read();
	int a=read(),b=read();p=1ll*a*qpow(b)%mod;k=read();
	prework();
	solve();
	printf("%d\n",(L[n][m]+mod)%mod);
}