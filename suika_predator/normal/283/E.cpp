#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int l,r,cnt,lazy;
	node *lson,*rson;
	inline void upd(){cnt=lson->cnt+rson->cnt;}
	inline void mark(){lazy^=1;cnt=(r-l+1)-cnt;}
	inline void fa_lazy(){if(lazy){lson->mark();rson->mark();lazy=0;}}
}*root,pool[233333];
int top;
node *build(int l,int r)
{
	node *tmp=&pool[top++];
	tmp->l=l;tmp->r=r;tmp->cnt=0;tmp->lazy=0;
	if(l!=r)
	{
		int mid=(l+r)/2;
		tmp->lson=build(l,mid);
		tmp->rson=build(mid+1,r);
	}
	return tmp;
}
void change(node *cur,int l,int r)
{
	if(cur->l==l&&cur->r==r)
	{
		cur->mark();
		return;
	}
	if(cur->lazy)cur->fa_lazy();
	if(cur->lson->r>=r)change(cur->lson,l,r);
	else if(cur->rson->l<=l)change(cur->rson,l,r);
	else change(cur->lson,l,cur->lson->r),change(cur->rson,cur->rson->l,r);
	cur->upd();
}
int query(node *cur,int l,int r)
{
	if(cur->l==l&&cur->r==r)
	{
		return cur->cnt;
	}
	if(cur->lazy)cur->fa_lazy();
	if(cur->lson->r>=r)return query(cur->lson,l,r);
	else if(cur->rson->l<=l)return query(cur->rson,l,r);
	else return query(cur->lson,l,cur->lson->r)+query(cur->rson,cur->rson->l,r);
}
struct que
{
	int t,l,r;
	inline bool operator<(const que &x)const{return t<x.t;}
}q[777777];
int qtop;
int n,k;
int a[233333],ans[233333];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int x,y,l,r,L,R,mid;
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		L=1,R=n;
		while(L<R)
		{
			mid=(L+R)/2;
			if(a[mid]<x)L=mid+1;
			else R=mid;
		}
		l=L;
		L=1,R=n;
		while(L<R)
		{
			mid=(L+R+1)/2;
			if(a[mid]>y)R=mid-1;
			else L=mid;
		}
		r=L;
		if(l<=r)
		{
			qtop++;q[qtop].l=l;q[qtop].r=r;q[qtop].t=l;
			qtop++;q[qtop].l=l;q[qtop].r=r;q[qtop].t=r+1;
		}
	}
	qtop++;q[qtop].l=1;q[qtop].r=n;q[qtop].t=1;
	for(int i=1;i<=n;i++)
	{
		qtop++;q[qtop].l=i;q[qtop].r=i;q[qtop].t=i+1;
	}
	sort(q+1,q+qtop+1);
	root=build(1,n);
	int p=1;
	for(int t=1;t<=n;t++)
	{
		while(q[p].t<=t)
		{
//			cout<<q[p].t<<' '<<q[p].l<<' '<<q[p].r<<endl;
			change(root,q[p].l,q[p].r);
			p++;
		}
		if(t>1)ans[t]+=query(root,1,t-1);
		if(t<n)ans[t]+=query(root,t+1,n);
	}
	long long cnt=1ll*n*(n-1)*(n-2)/6;
	for(int i=1;i<=n;i++)
	{
		cnt-=1ll*ans[i]*(ans[i]-1)/2;
	}
	printf("%lld\n",cnt);
	return 0;
}