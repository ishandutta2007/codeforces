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
int n;
int a[15];
const int mod=1e9+7;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
vector<int>Vec[1<<14];
int win[15][1<<14],all[15][1<<14];
int f[1<<14];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=0;i<(1<<n);++i){
		for(int j=1;j<=n;++j){
			if(i>>(j-1)&1) Vec[i].pb(j);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			win[i][1<<j-1]=1ll*a[i]*qpow(a[i]+a[j])%mod;
		}
	}
	for(int i=1;i<=n;++i){
		all[i][0]=1;
		for(int j=1;j<(1<<n);++j){
			all[i][j]=1ll*all[i][j^(j&-j)]*win[i][j&-j]%mod;
		}
	}
	for(int i=1;i<=n;++i){
		memset(f,0,sizeof(f));
		f[1<<i-1]=1;
		for(int j=1;j<(1<<n);++j){
			if(j==(1<<i-1)) continue ;
			if(~j&(1<<i-1)) continue ;
			f[j]=1;
			int bhf=0;
			for(int s=(j-1)&j;s;s=(s-1)&j)if(f[s]) {
				int t=1;
				for(int l:Vec[j^s]) t=1ll*t*all[l][s]%mod;
				(bhf+=1ll*f[s]*t%mod)%=mod;
			}
			(f[j]+=mod-bhf)%=mod;
		}
		(ans+=f[(1<<n)-1])%=mod;
	}
	printf("%d\n",ans);
}