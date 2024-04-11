#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 1000000007
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 200005
int N;
int mu[MN],phi[MN],p[MN/10],cnt;
bool vis[MN];
void init(int n){
	mu[1]=phi[1]=1;
	for(int i=2;i<=n;++i){
		if(!vis[i]){p[++cnt]=i;mu[i]=Mod-1;phi[i]=i-1;}
		for(int j=1;p[j]*i<=n;++j){
			vis[p[j]*i]=1;
			if(i%p[j]==0){mu[i*p[j]]=0;phi[i*p[j]]=phi[i]*p[j];break;}
			phi[i*p[j]]=phi[i]*(p[j]-1);
			mu[i*p[j]]=Mod-mu[i];
		}
//		cerr<<i<<": "<<mu[i]<<" "<<phi[i]<<endl;
	}
}
int n,siz[MN],fa[MN],dep[MN],w[MN],tot,rt;
int a[MN],inv[MN],val[MN],app[MN];
vector<int>d[MN];
vector<int>edge[MN];
void dfs(int x){
	siz[x]=1;w[x]=0;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
	//	cerr<<"edg: "<<x<<" "<<v<<" "<<fa[x]<<" "<<vis[v]<<endl;
		if(fa[x]==v||app[v])continue;
		fa[v]=x;
		dep[v]=dep[x]+1;
		dfs(v);
		siz[x]+=siz[v];
		if(siz[w[x]]<siz[v])w[x]=v;
	}
	if(max(siz[w[x]],N-siz[x])<=N/2) rt=x;
//	cerr<<"dfs: "<<x<<" "<<siz[x]<<" "<<w[x]<<endl;
}
int sum[MN],sumv[MN],ans;
vector<int>rub;
void DFS1(int x){
	int V=a[x];
	for(int i=0;i<d[V].size();++i){
		int t=d[V][i];
		ans=(ans+val[t]*sum[t]%Mod*phi[V]%Mod*dep[x])%Mod;
		ans=(ans+val[t]*sumv[t]%Mod*phi[V])%Mod;
		rub.push_back(t);
	}
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(fa[x]==v||app[v])continue;
		DFS1(v);
	}
}
void DFS2(int x){
	int V=a[x];
	for(int i=0;i<d[V].size();++i){
		int t=d[V][i];
//		cerr<<"ad: "<<t<<" "<<x<<" "<<a[x]<<endl;
		sum[t]=(sum[t]+phi[V])%Mod;
		sumv[t]=(sumv[t]+phi[V]*dep[x])%Mod;
	}
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(fa[x]==v||app[v])continue;
		DFS2(v);
	}
}
void work(int x,int tot){
	N=tot;
	fa[x]=0;
	dep[x]=0;
	rt=0;
	dfs(x);
	
	int tmp=rt;
	fa[rt]=0;
	dep[rt]=0;
	dfs(rt);
	rt=tmp;
//	cerr<<"work: "<<x<<" "<<tot<<" rt: "<<rt<<endl;
	
	int V=a[rt];
//	for(int i=1;i<=n;++i)assert(!sum[i]&&!sumv[i]);
	for(int i=0;i<d[V].size();++i){
		int t=d[V][i];
		rub.push_back(t);
		sum[t]=(sum[t]+phi[V])%Mod;
	}
	
	for(int i=0;i<edge[rt].size();++i){
		int v=edge[rt][i];
		if(app[v])continue;
		DFS1(v);DFS2(v);
	}
	
	for(int i=0;i<rub.size();++i)sum[rub[i]]=sumv[rub[i]]=0;
	rub.clear();
	app[rt]=1;
	for(int i=0;i<edge[tmp].size();++i){
		int v=edge[tmp][i];
		if(app[v])continue;
		work(v,siz[v]);
	}
}
signed main(){
	n=read();
	init(n);
	inv[1]=1;for(int i=2;i<=n;++i)inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)
			val[j]=(val[j]+i*inv[phi[i]]%Mod*mu[j/i])%Mod;
	for(int i=1;i<=n;++i){
		a[i]=read();//loc[a[i]]=i;
	}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)
			d[j].push_back(i);
	for(int i=1;i<n;++i){
		int u=read(),v=read();
	//	cerr<<"? "<<u<<" "<<v<<endl;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	work(1,n);
//	cerr<<"ans: "<<ans<<endl;
	printf("%lld\n",ans*2*inv[n]%Mod*inv[n-1]%Mod);
	return 0;
}