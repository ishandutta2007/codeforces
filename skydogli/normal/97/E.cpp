#include<bits/stdc++.h>
using namespace std;
#define MN 100005
int Log[MN],dfn[MN],low[MN],N,Time,Stack[MN],zhan[MN],fa[19][MN],odd[MN],dep[MN],suf[MN],n,m,q,C,app[MN],root[MN];
vector<int>edge[MN];
void tarjan(int x){
	dfn[x]=low[x]=++Time;
	app[x]=C;
	Stack[++N]=x;zhan[x]=1;
	for(int i=1;i<=Log[dep[x]];++i)fa[i][x]=fa[i-1][fa[i-1][x]];
	for(int i=0;i<edge[x].size();++i){
		if(fa[0][x]==edge[x][i])continue;
		if(!dfn[edge[x][i]]){
			dep[edge[x][i]]=dep[x]+1;
			fa[0][edge[x][i]]=x;
			tarjan(edge[x][i]);
			low[x]=min(low[x],low[edge[x][i]]);
		}
		else if(zhan[edge[x][i]]){
			low[x]=min(low[x],dfn[edge[x][i]]);
			odd[x]|=((dep[edge[x][i]]&1)==(dep[x]&1));
		}
	}
	zhan[x]=0;
	if(dfn[x]==low[x]){
		int tmp=N,flag=0;
		while(Stack[tmp]!=x&&!flag)
			flag|=odd[Stack[tmp--]];
		while(Stack[N]!=x){
			zhan[Stack[N]]=0;
			suf[Stack[N--]]+=flag;
		}
		N--;
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Log[dep[x]];i>=0;--i)
		if(dep[fa[i][x]]>=dep[y])x=fa[i][x];
	if(x==y)return x;
	for(int i=Log[dep[x]];i>=0;--i)
		if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
void getsum(int x){
	for(int i=0;i<edge[x].size();++i)
		if(fa[0][edge[x][i]]==x)
			suf[edge[x][i]]+=suf[x],getsum(edge[x][i]);
}
int main(){
	scanf("%d%d",&n,&m);
	int a,b,goal=2;
	for(int i=1;i<=n;++i){
		Log[i]=Log[i-1];
		if(i==goal){goal<<=1;Log[i]++;}
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	scanf("%d",&q);
	for(int i=1;i<=n;++i)if(!dfn[i])dep[i]=1,C++,root[i]=1,tarjan(i);
	for(int i=1;i<=n;++i)if(dep[i]==1)getsum(i);
	for(int i=1;i<=q;++i){
		scanf("%d%d",&a,&b);
		if(app[a]!=app[b]){puts("No");continue;}
		int LCA=lca(a,b);
		if((dep[a]+dep[b]-dep[LCA]-dep[LCA])&1){puts("Yes");continue;}
		if(suf[a]+suf[b]-(suf[LCA]<<1)>0)puts("Yes");
			else puts("No");
	}
	return 0;
}