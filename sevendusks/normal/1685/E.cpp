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
const int N=4*1e5+100;
int n,m,q,p[N],sum[N],pos;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct node
{
	int l,r,sum;
};
bool operator !=(node a,node b){return a.l!=b.l||a.r!=b.r||a.sum!=b.sum;}
node operator +(node a,node b)
{
	if (!a.l) return b;
	if (!b.l) return a;
	return (node){a.l,b.r,a.sum+b.sum+abs(a.r-b.l)};
}
namespace seg
{
	pair<int,int> MIN[N*4];
	int tag[N*4];
	node A[N*4],B[N*4];
	void pushup(int x)
	{
		MIN[x]=min(MIN[ls],MIN[rs]);
		A[x]=A[ls]+A[rs];B[x]=B[ls]+B[rs];
	}
	void upd(int x,int v){MIN[x].first+=v;tag[x]+=v;}
	void pushdown(int x)
	{
		if (tag[x])
		{
			upd(ls,tag[x]);upd(rs,tag[x]);
			tag[x]=0;
		}
	}
	void build(int x,int l,int r)
	{
		if (l==r)
		{
			MIN[x]=m_k(sum[l],l);
			A[x]=B[x]=(node){0,0,0};
			if (p[l]<n+1) A[x]=(node){p[l],p[l],0};
			if (p[l]>n+1) B[x]=(node){p[l],p[l],0};
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(x);
	}
	void change(int x,int l,int r,int ll,int rr,int v)
	{
		if (ll<=l&&rr>=r){upd(x,v);return;}
		int mid=(l+r)>>1;pushdown(x);
		if (ll<=mid) change(ls,l,mid,ll,rr,v);
		if (rr>mid) change(rs,mid+1,r,ll,rr,v);
		pushup(x);
	}
	void change_pos(int x,int l,int r,int wh,int v)
	{
		if (l==r)
		{
			A[x]=B[x]=(node){0,0,0};
			if (v<n+1) A[x]=(node){v,v,0};
			if (v>n+1) B[x]=(node){v,v,0};
			return;
		}
		int mid=(l+r)>>1;pushdown(x);
		if (wh<=mid) change_pos(ls,l,mid,wh,v);
		else change_pos(rs,mid+1,r,wh,v);
		pushup(x);
	}
	pair<int,int> query(int x,int l,int r,int ll,int rr)
	{
		if (ll<=l&&rr>=r) return MIN[x];
		int mid=(l+r)>>1;pair<int,int> ans=m_k(inf,inf);pushdown(x);
		if (ll<=mid) ans=min(ans,query(ls,l,mid,ll,rr));
		if (rr>mid) ans=min(ans,query(rs,mid+1,r,ll,rr));
		return ans;
	}
	node ask(int x,int l,int r,int ll,int rr,int op)
	{
		if (ll<=l&&rr>=r) return (op==1?B[x]:A[x]);
		int mid=(l+r)>>1;pushdown(x);node ans=(node){0,0,0};
		if (ll<=mid) ans=ask(ls,l,mid,ll,rr,op);
		if (rr>mid) ans=ans+ask(rs,mid+1,r,ll,rr,op);
		return ans;
	}
}
void change(int x,int v)
{
	if (p[x]==n+1) return;
	if (p[x]<n+1) seg::change(1,1,2*m,x,2*m,-v);
	else seg::change(1,1,2*m,x,2*m,v);
}
void upd(int x,int y)
{
	change(x,-1);change(y,-1);
	swap(p[x],p[y]);
	if (x<=m)
	{
		if (p[x]==n+1) pos=x;
		if (p[y]==n+1) pos=y;
	}
	seg::change_pos(1,1,2*m,x,p[x]);
	seg::change_pos(1,1,2*m,y,p[y]);
	change(x,1);change(y,1);
}
signed main()
{
	n=read();q=read();m=2*n+1;
	for (int i=1;i<=m;i++) p[i]=read(),p[m+i]=p[i];
	pos=find(p+1,p+1+m,n+1)-p;
	for (int i=1;i<=2*m;i++)
	{
		sum[i]=sum[i-1];
		if (p[i]<n+1) sum[i]--;
		if (p[i]>n+1) sum[i]++; 
	}
	seg::build(1,1,2*m);
	while (q--)
	{
		int x=read(),y=read();
		upd(x,y);upd(x+m,y+m);
		pair<int,int> tmp=seg::query(1,1,2*m,pos,pos+m-1);
		pair<int,int> d;
		if (pos==1) d=m_k(0,0);
		else d=seg::query(1,1,2*m,pos-1,pos-1);
		if (tmp.first<d.first)
		{
			int k=tmp.second;
			if (k>=m) k-=m;
			printf("%d\n",k);
			continue;
		}
		if (seg::ask(1,1,2*m,pos,pos+m-1,0)!=(node){1,n,n-1})
		{
			printf("%d\n",(pos>=m?pos-m:pos));
			continue;
		}
		if (seg::ask(1,1,2*m,pos,pos+m-1,1)!=(node){n+2,2*n+1,n-1})
		{
			printf("%d\n",pos-1);
			continue;
		}
		printf("-1\n");
	}
}