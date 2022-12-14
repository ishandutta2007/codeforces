#include <bits/stdc++.h>
using namespace std;
const int N=1005,M=5005,inf=0x3f3f3f3f;
int n,m,tot,u[M],v[M],nxt[3*M],fst[N],rfst[N],to[3*M],w[3*M],d[N],cnt[N];
bool from1[N],ton[N],inq[N];
void dfs1(int u) {
	from1[u]=true;
	for (int i=fst[u];i;i=nxt[i])
		if (!from1[to[i]]) dfs1(to[i]);
}
void dfs2(int u) {
	ton[u]=true;
	for (int i=rfst[u];i;i=nxt[i])
		if (!ton[to[i]]) dfs2(to[i]);
}
void adde(int *fst,int u,int v,int c=0) {
	nxt[++tot]=fst[u];fst[u]=tot;to[tot]=v;w[tot]=c;
}
bool on(int i) {return from1[i]&&ton[i];}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		scanf("%d%d",u+i,v+i);
		adde(fst,u[i],v[i]);
		adde(rfst,v[i],u[i]);
	}
	dfs1(1),dfs2(n);
	tot=0;
	for (int i=1;i<=n;i++) fst[i]=0,d[i]=inf;
	for (int i=1;i<=m;i++)
		if (on(u[i])&&on(v[i])) {
			adde(fst,u[i],v[i],2);
			adde(fst,v[i],u[i],-1);
		}
	for (int i=1;i<=n;i++)
		if (on(i)) adde(fst,n+1,i);
	queue<int> q;
	q.push(n+1);
	inq[n+1]=true;
	cnt[n+1]=1;
	while (!q.empty()) {
		int u=q.front();q.pop();inq[u]=false;
		if (cnt[u]>n) return puts("No"),0;
		for (int i=fst[u];i;i=nxt[i])
			if (d[to[i]]>d[u]+w[i]) {
				d[to[i]]=d[u]+w[i];
				if (!inq[to[i]]) cnt[to[i]]++,inq[to[i]]=true,q.push(to[i]);
			}
	}
	puts("Yes");
	for (int i=1;i<=m;i++)
		if (on(u[i])&&on(v[i])) printf("%d\n",d[v[i]]-d[u[i]]);
		else puts("1");
}