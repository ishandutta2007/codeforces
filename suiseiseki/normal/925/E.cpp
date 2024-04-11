#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int B=500;
int n,m,a[maxn],_a[maxn],pos[maxn],L[maxn],R[maxn],add[maxn/B+10],sum[maxn/B+10][maxn<<1],head[maxn],to[maxn],nxt[maxn],tot,ans;
int top[maxn],dep[maxn],siz[maxn],son[maxn],fa[maxn],id[maxn],mp[maxn],tim; bool col[maxn];
void addedge(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void dfs1(int x,int f){
	siz[x]=1;
	fa[x]=f;
	dep[x]=dep[f]+1;
	int maxson=-1;
	for(int i=head[x],y;i;i=nxt[i]){
		if((y=to[i])&&y!=f){
			dfs1(y,x);
			siz[x]+=siz[y];
			if(siz[y]>maxson){
				maxson=siz[y];
				son[x]=y;
			}
		}
	}
}
void dfs2(int x,int topf)
{
	id[x]=++tim,mp[tim]=x,top[x]=topf;
	if(son[x]) dfs2(son[x],topf);
	for(int i=head[x],y;i;i=nxt[i])
		if((y=to[i]) && y!=fa[x] && y!=son[x])
			dfs2(y,y);
}
inline void change(int x,int y)
{
	col[x]^=1;
	if(a[x]>=n+1-add[pos[x]]) ans-=y;
	sum[pos[x]][a[x]]-=y;
}
inline void modify(int l,int r,int v)
{
	for(int i=l,p=pos[i];i<=r;i++)
	{
		if(!col[i] && a[i]>=n+1-add[p]) ans--;
		if(!col[i]) sum[p][a[i]]--;
		a[i]+=v;
		if(!col[i]) sum[p][a[i]]++;
		if(!col[i] && a[i]>=n+1-add[p]) ans++;
	}
}
inline void update(int l,int r,int v)
{
	int p=pos[l],q=pos[r];
	if(p==q) { modify(l,r,v); return; }
	modify(l,R[p],v),modify(L[q],r,v);
	for(int i=p+1;i<q;i++)
	{
		if(v==1) add[i]++,ans+=sum[i][n+1-add[i]];
		else ans-=sum[i][n+1-add[i]],add[i]--;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
		scanf("%d",&fa[i]),addedge(fa[i],i);
	for(int i=1;i<=n;i++) scanf("%d",&_a[i]);
	dfs1(1,0),dfs2(1,1);
	for(int i=1;i<=n;i++)
	{
		pos[i]=(i-1)/B+1;
		if(pos[i]!=pos[i-1])
			L[pos[i]]=i,R[pos[i-1]]=i-1;
	}
	R[pos[n]]=n;
	for(int i=1;i<=n;i++) a[id[i]]=n-_a[i];
	for(int i=1;i<=n;i++) sum[pos[i]][a[i]]++;
	int x,y;
	while(m--){
		scanf("%d",&x);
		y=(x>0)?1:-1,x=abs(x);
		change(id[x],y);
		for(;x;x=fa[top[x]])
			update(id[top[x]],id[x],y);
		printf("%d ",ans);
	}
	putchar('\n');
	return 0;
}