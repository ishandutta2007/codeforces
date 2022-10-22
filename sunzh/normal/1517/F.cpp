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
const int mod=998244353;
int n;
int f[310][310],g[310][310],tf[310],tg[310];
int R=0;
bool can[310];
int mdep[310];
vector<int>vec[310];
void dfs(int x,int fa){
	f[x][0]=g[x][0]=1;
	mdep[x]=1;
	bool F=0;
	for(int v:vec[x]){
		if(v==fa) continue ;
		dfs(v,x);
		for(int i=0;i<mdep[x];++i){
			for(int j=0;j<mdep[v];++j){
				(tf[min(i,j+1)]+=1ll*f[x][i]*f[v][j]%mod)%=mod;
				(tg[max(i,j+1)]+=1ll*g[x][i]*g[v][j]%mod)%=mod;
				if(i+j+1<=R) (tf[i]+=1ll*f[x][i]*g[v][j]%mod)%=mod,(tf[j+1]+=1ll*g[x][i]*f[v][j]%mod)%=mod;
				else(tg[i]+=1ll*g[x][i]*f[v][j]%mod)%=mod,(tg[j+1]+=1ll*f[x][i]*g[v][j]%mod)%=mod;
			}
		}
		mdep[x]=max(mdep[x],mdep[v]+1);
		for(int i=0;i<mdep[x];++i) f[x][i]=tf[i],g[x][i]=tg[i],tf[i]=tg[i]=0;
	}
//	printf("can[%d]=%d\n",x,can[x]);
}
int qpow(int x,int k=mod-2){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;x=1ll*x*x%mod;k>>=1;
	}
	return res;
}
int main(){
	n=read();
	for(int i=1;i<n;++i) {
		int u=read(),v=read();vec[u].pb(v),vec[v].pb(u);
	}
	int ans=n-1;
	int last=1;
	for(int i=1;i<n;++i){
		R=i;
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
//		memset(t,0,sizeof(tmp));
		dfs(1,0);
		int sum=0;
		for(int j=0;j<mdep[1];++j){
			(sum+=f[1][j])%=mod;
		}
//		printf("i:%d,sum:%d\n",i,sum);
		(ans+=1ll*(i-1)*(sum-last+mod)%mod)%=mod;
//		printf("ans:%d\n",ans);
		last=sum;
	}
//	printf("%d\n",ans);
	printf("%d\n",1ll*ans*qpow(qpow(2,n))%mod);
	return 0;
}