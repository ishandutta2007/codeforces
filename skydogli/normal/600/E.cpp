#include<bits/stdc++.h>
using namespace std;
#define LL long long
inline int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 100005
int siz[MN],fa[MN],w[MN],col[MN],vis[MN],n,u,v,MAX;
LL ans[MN],sum;
vector<int>edge[MN];
void dfs1(int x){
	siz[x]=1;
	for(int i=0;i<edge[x].size();++i)
		if(edge[x][i]!=fa[x]){
			fa[edge[x][i]]=x;
			dfs1(edge[x][i]);
			siz[x]+=siz[edge[x][i]];
			if(siz[w[x]]<siz[edge[x][i]])w[x]=edge[x][i];
		}
}
void calc(int x,int op,int W){
	vis[col[x]]+=op;
	if(vis[col[x]]>MAX) MAX=vis[col[x]],sum=col[x];
		else if(vis[col[x]]==MAX) sum+=col[x];
	for(int i=0;i<edge[x].size();++i)
		if(edge[x][i]!=fa[x]&&edge[x][i]!=W)
			calc(edge[x][i],op,W);
}
void dfs2(int x,int op){
	for(int i=0;i<edge[x].size();++i){
		if(edge[x][i]!=fa[x]&&edge[x][i]!=w[x])
			dfs2(edge[x][i],0);
	}
	if(w[x]) dfs2(w[x],1);
	calc(x,1,w[x]);
	ans[x]=sum;
	if(!op){
		calc(x,-1,0);
		sum=0;
		MAX=0;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)col[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;++i)
		printf("%I64d\n",ans[i]);
	return 0;
}