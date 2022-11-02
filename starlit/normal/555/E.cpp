#include<bits/stdc++.h>
const int N=200005;
using namespace std;
int n,m,q,to[N*4],hd[N*4],lk[N],Lk[N],cnt=1,
dfn[N],low[N],scc[N],st[N],t,sc,de[N],f[19][N],
up[N],dw[N];
inline void add(int u,int v,int*L){
	//cerr<<u<<"~"<<v<<endl;
	to[++cnt]=v,hd[cnt]=L[u],L[u]=cnt;
}int u,v,w;
void dfs(int x,int y){
	if(dfn[x])return;
	dfn[x]=low[x]=++m;
	st[t++]=x;
	for(int i=lk[x];i;i=hd[i])
	if(i^y)dfs(to[i],i^1),
	low[x]=min(low[x],low[to[i]]);
	if(dfn[x]==low[x])
	for(sc++;st[t]^x;)
	scc[st[--t]]=sc;
}
void dfss(int x,int y){
	if(de[x])return;
	//cerr<<x<<"->"<<f[0][x]<<endl;
	de[x]=de[f[0][x]]+1;
	for(int i=0;f[i][x];i++)
	f[i+1][x]=f[i][f[i][x]];
	for(int s,i=Lk[x];i;i=hd[i])
	if(!de[s=to[i]])f[0][s]=x,dfss(s,i^1);
}
void dfs(int x){
	//cerr<<"ssfd "<<x<<endl;
	for(int s,i=Lk[x];i;i=hd[i])
	if(f[0][s=to[i]]==x)
	dfs(s),up[x]+=up[s],dw[x]+=dw[s];
	if(up[x]&&dw[x])puts("No"),exit(0);
}
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<m;i++)
	scanf("%d%d",&u,&v),
	add(u,v,lk),add(v,u,lk);
	for(int i=1;i<=n;i++)dfs(i,0);
	for(int i=1;i<=n;i++)
	for(int j=lk[i];j;j=hd[j])
	if((u=scc[i])^(v=scc[to[j]]))
	add(u,v,Lk);
	for(int i=1;i<=sc;i++)
	dfss(i,0);
	for(;q--;){
		scanf("%d%d",&u,&v);
		u=scc[u],v=scc[v];
		up[u]++,dw[v]++;
		if(de[u]>de[v])swap(u,v);
		for(int i=0;i<18;i++)
		if(de[v]-de[u]>>i&1)
		v=f[i][v];
		for(int i=17;~i;i--)
		if(f[i][u]^f[i][v])u=f[i][u],v=f[i][v];
		w=u^v?f[0][u]:u;
		if(!w)return puts("No"),0;
		up[w]--,dw[w]--;
	}
	for(int i=1;i<=sc;i++)
	if(de[i]<2)dfs(i);
	puts("Yes");
}