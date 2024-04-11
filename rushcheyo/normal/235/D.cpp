#include <bits/stdc++.h>
using namespace std;
const int N=3005;
int n,tot,fst[N],to[2*N],nxt[2*N],cir[N],pos[N],len,dep[N],fa[N],subt[N],st[N],top,dis[N];
bool vis[N];
void addedge(int u,int v) {
	nxt[++tot]=fst[u];fst[u]=tot;to[tot]=v;
	nxt[++tot]=fst[v];fst[v]=tot;to[tot]=u;
}
void fnd(int u) {
	if (len) return;
	vis[u]=true;
	for (int i=fst[u];i&&!len;i=nxt[i])
		if (to[i]!=fa[u]) {
			if (vis[to[i]]) {
				for (int j=u;j!=to[i];j=fa[j]) cir[++len]=j,pos[j]=len;
				cir[++len]=to[i],pos[to[i]]=len;
				return;
			}
			fa[to[i]]=u;
			fnd(to[i]);
		}
}
void dfs(int u) {
	st[++top]=u;
	for (int i=fst[u];i;i=nxt[i])
		if (to[i]!=fa[u]&&!pos[to[i]]) {
			fa[to[i]]=u;
			dep[to[i]]=dep[u]+1;
			subt[to[i]]=subt[u];
			dfs(to[i]);
		}
}
int main() {
	scanf("%d",&n);
	for (int i=1,u,v;i<=n;i++) {
		scanf("%d%d",&u,&v);
		addedge(u+1,v+1);
	}
	fnd(1);
	double ans=0;
	for (int i=1;i<=len;i++) {
		fa[cir[i]]=dep[cir[i]]=0;
		subt[cir[i]]=i;
		top=0;
		dfs(cir[i]);
		for (int j=1;j<=top;j++) {
			for (int k=1;k<=top;k++) vis[st[k]]=false;
			static int q[N];
			int h=0,t=0;
			q[t++]=st[j];
			dis[q[0]]=1;
			vis[q[0]]=true;
			while (h<t) {
				int u=q[h++];
				ans+=1.0/dis[u];
				for (int k=fst[u];k;k=nxt[k])
					if (!vis[to[k]]&&(to[k]==cir[i]||!pos[to[k]])) {
						q[t++]=to[k];
						vis[to[k]]=true;
						dis[to[k]]=dis[u]+1;
					}
			}
		}
	}
	for (int u=1;u<=n;u++)
		for (int v=1;v<=n;v++)
			if (subt[u]!=subt[v]) {
				int A=dep[u]+dep[v]+abs(subt[u]-subt[v])+1,B=dep[u]+dep[v]+len-abs(subt[u]-subt[v])+1,C=dep[u]+dep[v]+len;
				ans+=1.0/A+1.0/B-1.0/C;
			}
	printf("%.10f\n",ans);
}