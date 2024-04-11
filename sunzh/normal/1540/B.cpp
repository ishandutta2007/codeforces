#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
vector<int>vec[210];
int sz[210];
int fac[410],ifac[410];
void dfs1(int x,int fa){
	sz[x]=1;
	for(int v:vec[x]){
		if(v==fa) continue ;
		dfs1(v,x);
		sz[x]+=sz[v];
	}
}
int dep[210],cnt[210];
int ans;
const int mod=1e9+7;
int inv2=(mod+1>>1);
int invn=0;
int p[210][210];
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;x=1ll*x*x%mod;k>>=1;
	}
	return res;
} 
int iv[210];
int C(int x,int y){
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
void dfs2(int x,int fa,int FF){
	
	
	dep[x]=dep[fa]+1;
	if(x>FF){
		(ans+=sz[x])%=mod;
		for(int i=2;i<dep[x];++i){
			int a=dep[x]-i,b=i-2;
			int t=iv[a];
			(ans+=1ll*t*cnt[i]%mod*p[a-1][b]%mod)%=mod;
//			for(int j=0;j<=b;++j){
//				(ans+=1ll*t*iv[j]%mod*C(a-1+j,j)%mod*cnt[i]%mod)%=mod;
//			}
		}
	}
	for(int v:vec[x]){
		if(v==fa) continue ;
		cnt[dep[x]]=sz[x]-sz[v];
		dfs2(v,x,FF);
	}
}
int main(){
	fac[0]=1;
	for(int i=1;i<=400;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[400]=qpow(fac[400],mod-2);
	iv[1]=inv2;iv[0]=1;
	for(int i=2;i<=200;++i) iv[i]=1ll*iv[i-1]*inv2%mod;
	for(int i=399;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=0;i<=200;++i){
		p[i][0]=1;
		for(int j=1;j<=200;++j){
			p[i][j]=(p[i][j-1]+1ll*C(i+j,j)*iv[j]%mod)%mod;
		}
	}
	n=read();invn=qpow(n,mod-2);
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v),vec[v].pb(u); 
	}
	for(int i=1;i<=n;++i){
		dfs1(i,0); dfs2(i,0,i);
	}
//	printf("%d\n",ans);
	printf("%d\n",1ll*invn*ans%mod);
}