#include<bits/stdc++.h> 
#define maxn 300020
#define mod 1000000007

using namespace std;

int a[maxn],h[maxn],nxt[maxn*2],data[maxn*2],to[maxn*2],d[maxn],n,m,pre[maxn],deg[maxn],u,v,s,t,p,g,ans[maxn],he[maxn];
bool f,visit[maxn];
int l,r,que[maxn];

void sub_union(int x,int y)
{
	if (he[x]>h[y]) pre[y]=x;
	else if (he[x]<he[y]) pre[x]=y;
	else pre[y]=x,he[x]++;
}

int ffind(int x)
{
	if (x==pre[x]) return x;
	int tmp=ffind(pre[x]);
	pre[x]=tmp;
	return tmp;
}

void add_edge(int x,int y,int z)
{
	p++;
	data[p]=z;
	to[p]=y;
	nxt[p]=h[x];
	h[x]=p;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	for (int i=1;i<=n;i++) pre[i]=i,he[i]=1;
	p=0;
	memset(nxt,0,sizeof(nxt));
	memset(h,0,sizeof(h));
	memset(deg,0,sizeof(deg));
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		s=ffind(u);t=ffind(v);
		if (s!=t){
			sub_union(s,t);
			add_edge(u,v,i);
			add_edge(v,u,i);
			deg[u]++;deg[v]++;
		}
	}
	g=0;
	for (int i=1;i<=n;i++) if (d[i]>=0) g=(g+d[i])%2;
	if (g){
		f=true;
		for (int i=1;f&&i<=n;i++) if (d[i]<0) d[i]=1,f=false;
		if (f){
			printf("-1\n");
			return 0;
		}
	}
	for (int i=1;i<=n;i++) if (d[i]<0) d[i]=0;
	l=1;r=0;memset(visit,true,sizeof(visit));m=0;
	for (int i=1;i<=n;i++) if (deg[i]==1) que[++r]=i;
	while (l<=r){
		g=que[l++];
		visit[g]=false;
		for (int j=h[g];j;j=nxt[j])
		{
			if (visit[to[j]]){
				if (d[g]) ans[++m]=data[j],d[to[j]]=1-d[to[j]];
				deg[to[j]]--;
				if (deg[to[j]]==1) que[++r]=to[j];
			}
		}
	}
	printf("%d\n",m);
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}