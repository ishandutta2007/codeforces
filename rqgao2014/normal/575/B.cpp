#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int mod=1000000007;
struct edge {
	int to,next,tag;
} e[200005];
bool ok[100005];
int n,m,k,head[100005],pre[100005],s[1000005],num,fa[100005][20],d[100005],tag1[100005],tag2[100005],fatag[100005],power[1000005],ans;
struct edge_type {
	int u,v;
} ee[100005];
inline int find(int x) {
	return pre[x]==x?x:pre[x]=find(pre[x]);
}
inline void insert(int u,int v) {
	e[++num].to=v; e[num].next=head[u]; e[num].tag=1; head[u]=num;
	e[++num].to=u; e[num].next=head[v]; e[num].tag=0; head[v]=num;
}
void dfs(int now,int father,int depth) {
	fa[now][0]=father; d[now]=depth;
	for (int i=head[now];i;i=e[i].next) if (e[i].to!=father) {
		if (e[i].tag) fatag[e[i].to]=0; else fatag[e[i].to]=1;
		dfs(e[i].to,now,depth+1);
	}
}
inline int lca(int u,int v) {
	if (d[u]>d[v]) swap(u,v);
	for (int i=19;i>=0;i--) if (d[fa[v][i]]>=d[u]) v=fa[v][i];
	if (u==v) return u;
	for (int i=19;i>=0;i--) if (fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void dfs2(int now,int father) {
	for (int i=head[now];i;i=e[i].next) if (e[i].to!=father) {
		dfs2(e[i].to,now);
		tag1[now]+=tag1[e[i].to];
		tag2[now]+=tag2[e[i].to];
	}
}
int main() {
	scanf("%d",&n);
	power[1]=1;
	for (int i=2;i<=1000000;i++) power[i]=(power[i-1]<<1)%mod;
	for (int i=2;i<=1000000;i++) power[i]=(power[i]+power[i-1])%mod;
	for (int i=1;i<=n;i++) pre[i]=i;
	for (int i=1;i<n;i++) {
		int u,v,tag;
		scanf("%d%d%d",&u,&v,&tag);
		if (tag==0) {
			if (find(u)!=find(v)) pre[find(u)]=pre[v];
		} else ee[++m]=(edge_type){u,v};
	}
	for (int i=1;i<=m;i++) insert(find(ee[i].u),find(ee[i].v));
	dfs(find(1),0,1);
	for (int i=1;i<=n;i++) if (find(i)==i) ok[i]=true;
	for (int i=1;i<=19;i++)
		for (int j=1;j<=n;j++) if (ok[j]) fa[j][i]=fa[fa[j][i-1]][i-1];
	scanf("%d",&m);
	s[0]=find(1);
	for (int i=1;i<=m;i++) {
		scanf("%d",&s[i]);
		s[i]=find(s[i]);
		int u=s[i-1],v=s[i],t=lca(u,v);
		tag1[u]++; tag1[t]--; tag2[v]++; tag2[t]--;
	}
	dfs2(find(1),0);
	for (int i=2;i<=n;i++) if (ok[i]) {
		if (fatag[i]==0) (ans+=power[tag1[i]])%=mod; else (ans+=power[tag2[i]])%=mod;
	}
	printf("%d\n",ans);
	return 0;
}