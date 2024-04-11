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
const int mod=998244353;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int n,k,c;
int a[1<<17];
int dp[1<<17][17];
int mx[1<<17];
int id[1<<17];
int C[21][21];
int main(){
	n=read(),k=read(),c=read();
	C[0][0]=1;
	for(int i=1;i<=k;++i){
		for(int j=1;j<i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		C[i][0]=C[i][i]=1;
	}
	int ans=0;
	for(int i=1;i<=n;++i) a[i]=read(),ans^=a[i];
	for(int i=1;i<=n;++i){
		mx[i]=0;
		for(int j=1;j<=k;++j) mx[i]=max(mx[i],a[i]^(a[i]-k));
		id[i]=i;
	}
	sort(id+1,id+n+1,[&](int x,int y){return mx[x]<mx[y];});
	dp[0][0]=1;
	int pw=1;
	for(int i=1;i<=n;++i){
		int va=a[id[i]];
		while(pw<=mx[id[i]]) pw<<=1;
		for(int t=k-1;t>=0;--t){
			for(int j=1;j+t<=k;++j){
				for(int pl=0;pl<pw;++pl){
					(dp[pl^va^(va-j)][j+t]+=1ll*dp[pl][t]*C[j+t][t]%mod)%=mod;
				}
			}
		}
	}
	int p=qpow(qpow(n),k);
	for(int i=0;i<(1<<c);++i){
		printf("%d ",1ll*p*dp[i^ans][k]%mod);
	}
}