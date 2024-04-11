#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<unordered_map>
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
const int mod=998244353;
int n,m;
int f[3010][3010],g[3010][3010];
unordered_map<int,int>ma;
inline int qpow(int x,int k){
	x%=mod;
	if(ma.count(x)) return ma[x];
	int res=1,t=x;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return ma[t]=res;
} 
int SA,SB;
int op[200010],val[200010];
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) op[i]=read();
	for(int i=1;i<=n;++i) val[i]=read();
	for(int i=1;i<=n;++i){
		if(op[i]==1) (SA+=val[i])%=mod;else (SB+=val[i])%=mod;
	}
	ma.clear();
	for(int i=m;i>=0;--i){ 
		f[i][m-i]=g[i][m-i]=1;
		for(int j=min(m-i-1,SB);j>=0;--j){
			f[i][j]=(1ll*(SA+i+1)*qpow(SA+i+SB-j,mod-2)%mod*f[i+1][j]%mod+1ll*(SB-j)*qpow(SA+i+SB-j,mod-2)%mod*f[i][j+1]%mod)%mod;
			g[i][j]=(1ll*(SA+i)*qpow(SA+i+SB-j,mod-2)%mod*g[i+1][j]%mod+1ll*(SB-j-1)*qpow(SA+i+SB-j,mod-2)%mod*g[i][j+1]%mod)%mod;
		}
	}
	for(int i=1;i<=n;++i){
		if(op[i]==1) printf("%lld\n",1ll*val[i]*f[0][0]%mod);
		else printf("%lld\n",1ll*val[i]*g[0][0]%mod);
	}
	return 0;
}