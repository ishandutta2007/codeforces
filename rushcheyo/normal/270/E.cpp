#include <cstdio>
const int N=200005;
int n,m,nxt[2*N],fst[N],to[2*N],cap[2*N],f[N],q[N],h,t,ans[N];
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1,u,v,w;i<=m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		nxt[2*i]=fst[u];fst[u]=2*i;to[2*i]=v;cap[2*i]=cap[2*i+1]=w;
		nxt[2*i+1]=fst[v];fst[v]=2*i+1;to[2*i+1]=u;
		f[u]+=w,f[v]+=w;
		ans[i]=-1;
	}
	for (int i=1;i<=n;i++) f[i]>>=1;
	q[t++]=1;
	while (h<t) {
		int u=q[h++];
		for (int i=fst[u];i;i=nxt[i])
			if (ans[i>>1]==-1) {
				ans[i>>1]=i&1;
				f[to[i]]-=cap[i];
				if (f[to[i]]==0&&to[i]!=n) q[t++]=to[i];
			}
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
}