#include<stdio.h>
# include <bits/stdc++.h>
using namespace std;
struct node
{
	long long val;
	long long l;
	long long r;
	long long sum;
};
node tree[1000000];
long long a[100001];
void build(int x,int l,int r)
{
	if (l==r)
	{
		tree[x].val=max(0LL,a[l]);
		tree[x].l=max(0LL,a[l]);
		tree[x].r=max(0LL,a[l]);
		tree[x].sum=a[l];
	}
	else
	{
		build(x*2,l,(l+r)/2);
		build(x*2+1,(l+r)/2+1,r);
			tree[x].r=max(tree[2*x+1].sum+tree[2*x].r,tree[2*x+1].r);
			tree[x].l=max(tree[2*x].l,tree[2*x].sum+tree[2*x+1].l);

		tree[x].val=max(tree[2*x+1].val,max(tree[2*x].val,tree[2*x].r+tree[2*x+1].l));
		tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
		if (tree[x].sum<-100000000000000LL)tree[x].sum=-100000000000000LL;
	}
}
node query(long long x,long long s,long long e,long long l,long long r)
{
	node ans;
	ans.val=-100000;
	ans.l=-100000;
	ans.r=-100000;
	ans.sum=-100000;
	if (s>r || e<l)
		return ans;
	if (s<=l && e>=r)
		return tree[x];
	node p1=query(x*2,s,e,l,(l+r)/2);
	node p2=query(x*2+1,s,e,(l+r)/2+1,r);
	if (p1.val==-100000 && p1.r==100000 && p1.l==100000 && p1.sum==-100000)
		return p2;
	if (p2.val==-100000 && p2.r==100000 && p2.l==100000 && p2.sum==-100000)
		return p1;
	ans.r=max(p1.r+p2.sum,p2.r);
	ans.l=max(p1.sum+p2.l,p1.l);
	ans.val=max(p1.val,max(p2.val,p1.r+p2.l));
	return ans;
}
void update(int x,int i,long long v,int l,int r)
{
	if (i<l || i>r)
		;
	else if (i==l && i==r)
	{
		tree[x].val=max(v,0LL);
		tree[x].l=max(v,0LL);
		tree[x].r=max(v,0LL);
		tree[x].sum=v;
	}
	else
	{
		int left=2*x;
		int right=left+1;
		int mid=(l+r)/2;
		update(left,i,v,l,mid);
		update(right,i,v,mid+1,r);
		tree[x].val=max(tree[left].val,max(tree[right].val,tree[left].r+tree[right].l));
		tree[x].r=max(tree[right].r,tree[right].sum+tree[left].r);
		tree[x].l=max(tree[left].sum+tree[right].l,tree[left].l);
		tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	build(1,1,n);
	for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        update(1,x,-100000000000000LL,1,n);
        printf("%I64d\n",max(0LL,tree[1].val));
    }
}