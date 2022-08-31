#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define bel(x) (((x)-1)/300)
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 110000
int head[MAXN],next[MAXN*2],p[MAXN*2],c[MAXN];
int dx[MAXN];int t1,t2;int sum[MAXN];int n,m;int st[MAXN],ed[MAXN];
int gg[MAXN];
struct jsb
{
	int v,k,l,r,id;
}data[MAXN];
int ans[MAXN];
inline bool cmp(const jsb &a,const jsb &b)
{
	if(bel(a.l)==bel(b.l))
	{
		if(bel(a.l)&1)
		return a.r<b.r;
		else return a.r>b.r;
	}
	return a.l<b.l;
}
inline void L(int a,int b)
{
	t1++;p[t1]=b;next[t1]=head[a];head[a]=t1;
}
void dfs(int x)
{
	st[x]=++t2;dx[t2]=x;
	for(int u=head[x];u;u=next[u])
	if(!st[p[u]])dfs(p[u]);
	ed[x]=t2;
}
inline void add(int x)
{
	gg[c[dx[x]]]++;sum[gg[c[dx[x]]]]++;
}
inline void del(int x)
{
	sum[gg[c[dx[x]]]]--;gg[c[dx[x]]]--;
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&c[i]);
	rep(i,1,n-1){int a,b;scanf("%d%d",&a,&b);L(a,b);L(b,a);}
	dfs(1);
	rep(i,1,m)
	{
		scanf("%d%d",&data[i].v,&data[i].k);
		data[i].id=i;
		data[i].l=st[data[i].v];
		data[i].r=ed[data[i].v];
		}
	sort(data+1,data+1+m,cmp);
	int l,r;l=0;r=0;
	rep(i,1,m)
	{
		while(r<data[i].r)add(++r);
		while(l>data[i].l)add(--l);
		while(r>data[i].r)del(r--);
		while(l<data[i].l)del(l++);
		ans[data[i].id]=sum[data[i].k];
	}
	rep(i,1,m)printf("%d\n",ans[i]);
}