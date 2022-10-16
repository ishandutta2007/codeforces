#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>

using namespace std;
int n,m;
int a[233333];
queue<int> q[233333];
vector<int> NEXT[233333];
struct node
{
	int l,r,sum;
	node *lson,*rson;
	inline void upd(){sum=lson->sum+rson->sum;}
}*root[233333],pool[5555555];
int top;
node *build(int l,int r)
{
	node *tmp=&pool[top++];
	tmp->l=l;tmp->r=r;
	if(l==r)tmp->sum=(q[a[l]].front()==l);
	if(l!=r)
	{
		int mid=(l+r)>>1;
		tmp->lson=build(l,mid);
		tmp->rson=build(mid+1,r);
		tmp->upd();
	}
	return tmp;
}
node *change(node *cur,int pos,int d)
{
//	cout<<"change "<<cur->l<<' '<<cur->r<<' '<<cur->sum<<' '<<pos<<' '<<d<<endl;
	node *tmp=&pool[top++];
	tmp->l=cur->l;tmp->r=cur->r;
	if(tmp->l==tmp->r)
	{
		tmp->sum=d;
		return tmp;
	}
	if(pos<=cur->lson->r)tmp->lson=change(cur->lson,pos,d),tmp->rson=cur->rson;
	else tmp->lson=cur->lson,tmp->rson=change(cur->rson,pos,d);
	tmp->upd();
	return tmp;
}
int query(node *cur,int k)
{
//	cout<<"query "<<cur->l<<' '<<cur->r<<' '<<cur->sum<<' '<<k<<endl;
	if(k>cur->sum)return n+1;
	if(cur->l==cur->r)return cur->l;
	if(cur->lson->sum>=k)return query(cur->lson,k);
	else return query(cur->rson,k-cur->lson->sum);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		q[a[i]].push(i);
	}
	root[2]=build(1,n);
	for(int i=1;i<n;i++)
	{
//		cout<<"fafa"<<' '<<i<<' '<<a[i]<<endl;
		root[2*i+1]=change(root[2*i],i,0);
		q[a[i]].pop();
		if(!q[a[i]].empty())root[2*i+2]=change(root[2*i+1],q[a[i]].front(),1);
		else root[2*i+2]=root[2*i+1];
	}
	for(int i=1;i<=n;i++)
	{
		int cur=1,ans=0;
		while(cur!=n+1)
		{
			ans++;
			cur=query(root[2*cur],i+1);
		}
		printf("%d ",ans);
	}
	return 0;
}