/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define ls x+x
#define rs x+x+1
#define len(a) (int)a.size()
using namespace std;
const int N=3*1e5+100,M=1e6+100;
int n,m,MIN[M*4],tag[M*4];
struct node
{
	int l,r,w;
}sh[N];
bool operator <(node a,node b){return a.w<b.w;}
void pushup(int x)
{
	MIN[x]=min(MIN[ls],MIN[rs]);
}
void pushdown(int x)
{
	if (tag[x])
	{
		MIN[ls]+=tag[x];MIN[rs]+=tag[x];
		tag[ls]+=tag[x];tag[rs]+=tag[x];
		tag[x]=0;
	}
}
void change(int x,int l,int r,int ll,int rr,int v)
{
	if (ll<=l&&rr>=r){MIN[x]+=v;tag[x]+=v;return;}
	int mid=(l+r)>>1;pushdown(x);
	if (ll<=mid) change(ls,l,mid,ll,rr,v);
	if (rr>mid) change(rs,mid+1,r,ll,rr,v);
	pushup(x);
}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void add(int x,int v)
{
	if (!x) return;
	change(1,1,m-1,sh[x].l,sh[x].r-1,v);
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) sh[i]=(node){read(),read(),read()};
	sort(sh+1,sh+1+n);
	int l=n,r=n,ans=inf;
	add(n,1);
	if (MIN[1]!=0) ans=0;
	while (l<=r&&l>=1)
	{
		if (MIN[1]==0) add(--l,1);
		else add(r--,-1);
		if (MIN[1]!=0) ans=min(ans,sh[r].w-sh[l].w);
	}
	printf("%d\n",ans);
}