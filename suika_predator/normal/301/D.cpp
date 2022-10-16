#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
struct que
{
	int r,ty,id;//ty=0:change ty=1:query
	que *next;
}*h[233333],pool[5555555];
int top;
int n,m;
inline void addq(int l,int r,int ty,int id)
{
//	cout<<"addq "<<l<<' '<<r<<' '<<ty<<' '<<id<<endl;
	que *tmp=&pool[top++];tmp->r=r;tmp->ty=ty;tmp->id=id;tmp->next=h[l];h[l]=tmp;
}
int BIT[233333];
void change(int pos,int d)
{
//	cout<<"change "<<pos<<' '<<d<<endl;
	for(int x=pos;x<=n;x+=x&-x)
		BIT[x]+=d;
}
int query(int pos)
{
//	cout<<"query "<<pos<<endl;
	int ret=0;
	for(int x=pos;x;x-=x&-x)
		ret+=BIT[x];
	return ret;
}
int a[233333],pos[233333],ans[233333];
int main()
{
	int l,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		if(l>r)swap(l,r);
		addq(l,r,1,i);
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
		{
			l=pos[i],r=pos[j];
			if(l>r)swap(l,r);
			addq(l,r,0,0);
		}
	for(int i=n;i>=1;i--)
	{
		for(que *tmp=h[i];tmp;tmp=tmp->next)
		{
			if(tmp->ty==0)change(tmp->r,1);
			else ans[tmp->id]=query(tmp->r);
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}