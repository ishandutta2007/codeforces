#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=524288;
struct node
{
	int l,r,cnt;
	node *lson,*rson;
}*root,pool[MAXN*2];
int top;
int n,m;
node* build(int l,int r)
{
	node *tmp=&pool[top++];
	tmp->l=l;tmp->r=r;
	if(l==r)return tmp;
	int mid=(l+r)/2;
	tmp->lson=build(l,mid);
	tmp->rson=build(mid+1,r);
	return tmp;
}
void add(node *cur,int x,int dep)
{
	//cout<<"change "<<cur->l<<' '<<cur->r<<' '<<x<<' '<<dep<<endl;
	if(!dep)
	{
		cur->cnt=1;
		return;
	}
	if((x>>(dep-1))&1)add(cur->rson,x,dep-1);
	else add(cur->lson,x,dep-1);
	cur->cnt=cur->lson->cnt+cur->rson->cnt;
}
int query(node *cur,int x,int dep)
{
	//cout<<"query "<<cur->l<<' '<<cur->r<<' '<<x<<' '<<dep<<endl;
	if(!dep)return cur->l;
	if((x>>(dep-1))&1)
	{
		if(cur->rson->cnt<cur->rson->r-cur->rson->l+1)return query(cur->rson,x,dep-1);
		else return query(cur->lson,x,dep-1);
	}
	else
	{
		if(cur->lson->cnt<cur->lson->r-cur->lson->l+1)return query(cur->lson,x,dep-1);
		else return query(cur->rson,x,dep-1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int a,cur=0;
	root=build(0,MAXN-1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		add(root,a,19);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a);
		cur^=a;
		printf("%d\n",query(root,cur,19)^cur);
	}
	return 0;
}