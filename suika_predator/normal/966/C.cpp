#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
struct node
{
	int cnt;
	node *son[2];
}*root,pool[7777777];
int top;
void add(node *cur,long long x,int dep,int delta)
{
	cur->cnt+=delta;
	if(dep==-1)return;
	int ty=(x>>dep)&1;
	if(!cur->son[ty])cur->son[ty]=&pool[top++];
	add(cur->son[ty],x,dep-1,delta);
}
long long query(node *cur,long long x,long long qwq,int dep)//bound=x,qwq^x<x
{
//	cout<<"query "<<x<<' '<<qwq<<' '<<dep<<endl;
	if((qwq^x)>x)return -1;
	if(dep==-1)return qwq;
	int ty=(x>>dep)&1;
	if(cur->son[!ty]&&cur->son[!ty]->cnt)
	{
		long long tmp=query(cur->son[!ty],x,qwq+(!ty)*(1ll<<dep),dep-1);
		if(tmp!=-1)return tmp;
	}
	if(cur->son[ty]&&cur->son[ty]->cnt)return query(cur->son[ty],x,qwq+(ty)*(1ll<<dep),dep-1);
	return -1;
}
int n,m;
long long num[233333],xsum,ans[233333];
int main()
{
	scanf("%d",&n);
	root=&pool[top++];
	for(int i=1;i<=n;i++)scanf("%lld",&num[i]),xsum^=num[i],add(root,num[i],60,1);
	for(int i=1;i<=n;i++)
	{
		long long tmp=query(root,xsum,0,60);
		if(tmp==-1)
		{
			printf("No\n");
			return 0;
		}
		add(root,tmp,60,-1);
		ans[n-i+1]=tmp;
		xsum^=tmp;
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",ans[i]);
	}
	printf("\n");
//	long long xx=0;for(int i=1;i<=n;i++){xx^=ans[i];cout<<xx<<' ';}
	return 0;
}