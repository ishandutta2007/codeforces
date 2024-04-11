#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,k,tot,ans,con[N],fr[N],nxt[2*N],fst1[N],fst2[N],to[2*N],w[2*N],clk,dfn[N],low[N],st[N],top;
bool ins[N],in0[N],vis[N],out[N];
void tarjan(int u){
	dfn[u]=low[u]=++clk;
	st[++top]=u;
	ins[u]=1;
	for(int i=fst1[u];i;i=nxt[i])
		if(!dfn[to[i]])tarjan(to[i]),low[u]=min(low[u],low[to[i]]);
		else if(ins[to[i]])low[u]=min(low[u],dfn[to[i]]);
	if(low[u]==dfn[u]){
		k++;
		do{
			ins[st[top]]=0;
			con[st[top]]=k;
		}while(st[top--]!=u);
	}
}
void dfs(int u){
	vis[u]=1;
	for(int i=fst2[u];i;i=nxt[i])
		if(!vis[to[i]]){
			dfs(to[i]);
			if(w[i])ans++,out[w[i]]=1;
		}
}
int main(){
#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",fr+i,to+i,w+i);
		if(!w[i])nxt[i]=fst1[fr[i]],fst1[fr[i]]=i;
	}
	tot=m;
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=m;i++)
		if(!w[i]&&con[fr[i]]!=con[to[i]]){
			in0[con[to[i]]]=1;
			nxt[++tot]=fst2[con[fr[i]]];fst2[con[fr[i]]]=tot;to[tot]=con[to[i]];w[tot]=0;
		}
	for(int i=1;i<=m;i++)
		if(w[i]&&con[fr[i]]!=con[to[i]]&&!in0[con[to[i]]]){
			nxt[++tot]=fst2[con[fr[i]]];fst2[con[fr[i]]]=tot;to[tot]=con[to[i]];w[tot]=i;
		}
	dfs(con[1]);
	for(int i=1;i<=k;i++)if(!vis[i])return puts("-1"),0;
	printf("%d\n",ans);
	for(int i=1;i<=m;i++)if(out[i])printf("%d%c",i," \n"[--ans==0]);
}