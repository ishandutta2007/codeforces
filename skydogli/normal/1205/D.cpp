#include<bits/stdc++.h>
using namespace std;
#define MN 1005
int siz[MN],fa[MN],w[MN];
vector<int>edge[MN];
int n,now,ad,rt;
void dfs1(int x){
	siz[x]=1;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;
		dfs1(v);
		siz[x]+=siz[v];
		if(siz[w[x]]<siz[v])w[x]=v;
	}
	if(max(n-siz[x],siz[w[x]])<=n/2) rt=x;
}
bool cmp(int a,int b){return siz[a]<siz[b];}
void dfs(int x,int dep){
	int tmp=now;
	printf("%d %d %d\n",x,fa[x],now-dep);
	now+=ad;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(fa[x]==v)continue;
		dfs(v,tmp);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs1(1);
	fa[rt]=0;dfs1(rt);
	sort(edge[rt].begin(),edge[rt].end(),cmp);
	int pos=0,tot=0;
	for(int i=0;i<edge[rt].size();++i){
		tot+=siz[edge[rt][i]];
		if(tot*3>=n){pos=i+1;break;}
	}
	now=1;ad=1;
//	cerr<<"tot: "<<tot<<endl;
	for(int i=0;i<pos;++i){
		dfs(edge[rt][i],0);
	}
	ad=tot+1;now=tot+1;
	for(int i=pos;i<edge[rt].size();++i){
		dfs(edge[rt][i],0);
	}
	return 0;
}