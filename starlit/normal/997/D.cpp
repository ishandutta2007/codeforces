#include<bits/stdc++.h>
const int N=4003,K=80,M=998244353;//!!!
#define rep for(int s,i=lk[x];i;i=hd[i])if((s=to[i])^y)
using namespace std;
int k,ans,u,v,tp[K],c[K][K],h[K];
struct dat{
	int n,to[N<<1],hd[N<<1],lk[N],cnt,
	f[N][K],g[K];
	inline void add(int u,int v){
		to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
	}
	void dfs(int x,int y){
		rep dfs(s,x);
		f[x][0]=1;
		rep for(int i=2;i<=k;i+=2)
		tp[i]=(tp[i]+f[s][i-2])%M;
		for(int i=2;i<=k;i+=2){
			h[i]=1ll*i*tp[i]%M;
			for(int j=2;j<=i;j+=2)
			f[x][i]=(f[x][i]+1ll*f[x][i-j]*tp[j])%M,
			h[i]=(h[i]+1ll*h[i-j]*tp[j])%M;
		}
		//cerr<<x<<"::\n";
		//cerr<<"ini:";
		//for(int i=2;i<=k;i+=2)
		//cerr<<f[x][i]<<' ';cerr<<endl;
		//cerr<<"add:";
		//for(int i=2;i<=k;i+=2)
		//cerr<<h[i]<<' ';cerr<<endl;
		for(int i=2;i<=k;i+=2)
		g[i]=(g[i]+h[i])%M,tp[i]=h[i]=0;
	}
	inline void rd(){
		g[0]=n;
		for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),
		add(u,v),add(v,u);
		dfs(1,0);
		//cerr<<"fin:";
		//for(int i=0;i<=k;i+=2)
		//cerr<<g[i]<<' ';
		//cerr<<endl;
	}
}T1,T2;
int main(){
	scanf("%d%d%d",&T1.n,&T2.n,&k);
	T1.rd(),T2.rd();
	for(int i=0;i<=k;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;
	}
	for(int i=0;i<=k;i+=2)
	ans=(ans+1ll*T1.g[i]*T2.g[k-i]%M*c[k][i])%M;
	printf("%d",ans);
}/*
3 2 4
1 2
2 3
1 2
*/