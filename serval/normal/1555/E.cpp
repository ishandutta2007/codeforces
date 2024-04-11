#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e6+5;
const int C=N<<2;
int n,m;
struct seg
{
	int l,r,w;
	seg(){}
	void read()
	{
		scanf("%d%d%d",&l,&r,&w);
		r--;
	}
};
seg s[N];
bool cmp(seg a,seg b)
{
	return a.w<b.w;
}
int l,ans;
int mn[C],add[C];
void pushdown(int u)
{
	if (add[u])
	{
		mn[u<<1]+=add[u];
		add[u<<1]+=add[u];
		mn[u<<1^1]+=add[u];
		add[u<<1^1]+=add[u];
		add[u]=0;
	}
}
void update(int u)
{
	mn[u]=min(mn[u<<1],mn[u<<1^1]);
}
void cover(int u,int l,int r,int ql,int qr,int v)
{
	if (r<ql||qr<l)
		return;
	if (ql<=l&&r<=qr)
	{
		mn[u]+=v;
		add[u]+=v;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(u);
	cover(u<<1,l,mid,ql,qr,v);
	cover(u<<1^1,mid+1,r,ql,qr,v);
	update(u);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		s[i].read();
	sort(s+1,s+n+1,cmp);
	l=1;
	ans=s[n].w-s[1].w;
	for (int i=1;i<=n;i++)
	{
		cover(1,1,m-1,s[i].l,s[i].r,1);
		if (mn[1]>0)
			ans=min(ans,s[i].w-s[l].w);
		while (s[l].w<s[i].w&&mn[1]>0)
		{
			ans=min(ans,s[i].w-s[l].w);
			cover(1,1,m-1,s[l].l,s[l].r,-1);
			l++;
		}
		if (mn[1]>0)
			ans=min(ans,s[i].w-s[l].w);
	}
	printf("%d\n",ans);
	return 0;
}