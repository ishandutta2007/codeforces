#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cassert>
#include<bitset>

using namespace std;
const int inf=1073741823;
struct node
{
	int cnt;
	node *lson,*rson;
}*root,pool[15000000];
int top;
void change(node *cur,int l,int r,int pos)
{
	cur->cnt++;
//	cout<<"change "<<l<<' '<<r<<' '<<(bitset<30>)pos<<' '<<cur->cnt<<endl;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(pos<=mid)
	{
		if(!cur->lson)
		{
			cur->lson=&pool[top++];
		}
		change(cur->lson,l,mid,pos);
	}
	else
	{
		if(!cur->rson)
		{
			cur->rson=&pool[top++];
		}
		change(cur->rson,mid+1,r,pos);
	}
}
int query(node *cur,int l,int r,int x)
{
	assert(cur->cnt);
//	cout<<"query "<<l<<' '<<r<<' '<<(bitset<30>)x<<' '<<cur->cnt<<endl;
	cur->cnt--;
	if(l==r)return l;
	int mid=(l+r)>>1;
//	cout<<x<<' '<<((l^r)+1)<<' '<<(x&((l^r)+1))<<' '<<(cur->lson?cur->lson->cnt:0)<<' '<<(cur->rson?cur->rson->cnt:0)<<endl;
	if(x&(((l^r)+1)>>1))
	{
		if(cur->rson&&cur->rson->cnt)
			return query(cur->rson,mid+1,r,x);
		else
			return query(cur->lson,l,mid,x);
	}
	else
	{
		if(cur->lson&&cur->lson->cnt)
			return query(cur->lson,l,mid,x);
		else
			return query(cur->rson,mid+1,r,x);
	}
		
}
int n,m;
int a[333333],p[333333];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	root=&pool[top++];
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),change(root,0,inf,p[i]);//,cout<<p[i]<<' '<<(a[1]^p[i])<<endl;;
	for(int i=1;i<=n;i++)
	{
		int tmp=query(root,0,inf,a[i]);
//		cout<<(bitset<30>)a[i]<<' '<<(bitset<30>)tmp<<endl;
		printf("%d ",a[i]^tmp);
	}
	return 0;
}