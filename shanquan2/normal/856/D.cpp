#include<bits/stdc++.h>
using namespace std;

struct edge{
	int nxt,to;
}e[200005];
struct fe{
	int x,y,w;
};
vector<fe> a[200005];
int dep[200005],ft[200005],tr[200005],f[200005],d[200005],r[200005],cnt=1,n,fa[200005],up[200005][18],q;
void dfs0(int x){
	d[x]=cnt++;
	for(int i=ft[x];i;i=e[i].nxt){
		int y=e[i].to;dep[y]=dep[x]+1;
		dfs0(y);
	}
	r[x]=cnt;
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;i>=0;i--)if(dep[up[x][i]]>=dep[y])x=up[x][i];
	if(x==y)return x;
	for(int i=17;i>=0;i--)if(up[x][i]!=up[y][i])x=up[x][i],y=up[y][i];
	return fa[x];
}
void add(int x,int w){
	for(;x<cnt;x+=x&-x)tr[x]+=w;
}
int query(int x){
	int ans=0;
	for(;x;x-=x&-x)ans+=tr[x];
	return ans;
}
void dfs(int x){
	int s=0;
	for(int i=ft[x];i;i=e[i].nxt)dfs(e[i].to),s+=f[e[i].to];
	f[x]=s;
	for(int i=0;i<a[x].size();i++){
		int u=a[x][i].x,v=a[x][i].y;
		int ans=query(d[u])+query(d[v])+s+a[x][i].w;
		if(ans>f[x])f[x]=ans;
	}
	int t=s-f[x];
	add(r[x],-t);add(d[x],t);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[i]);up[i][0]=fa[i];
		e[i]=(edge){ft[fa[i]],i},ft[fa[i]]=i;
	}
	for(int i=1;i<18;i++)for(int j=1;j<=n;j++)up[j][i]=up[up[j][i-1]][i-1];
	dep[1]=1;dfs0(1);
	for(int i=0;i<q;i++){
		int x,y,w;scanf("%d%d%d",&x,&y,&w);
		a[lca(x,y)].push_back((fe){x,y,w});
	}
	dfs(1);
	printf("%d\n",f[1]);
	return 0;
}