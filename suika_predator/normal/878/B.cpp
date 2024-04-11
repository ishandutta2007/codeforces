#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int n,m,k;
int tmp,last;
long long ans,ans2;
struct node
{
	int val,len;
	node *l,*r;
}pool[233333];
//stack<pair<int,int> > ls,rs;//len,val
int top;
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		if(tmp==last)
		{
			pool[top].len++;
		}
		else
		{
			top++;
			pool[top].l=&pool[top-1];
			pool[top].r=&pool[top+1];
			pool[top].val=tmp;
			pool[top].len=1;
		}
		last=tmp;
	}
	pool[0].r=&pool[1];pool[top+1].l=&pool[top];pool[top+1].val=-1;
	for(node *cur=&pool[1];cur!=&pool[top+1];)
	{
		ans+=1ll*cur->len/k*m;
		cur->len%=k;
		if(cur->len==0)
		{
			if(cur->l->val==cur->r->val)
			{
				cur->l->len+=cur->r->len;
				cur->l->r=cur->r->r;
				cur->r->r->l=cur->l;
				cur=cur->l;
			}
			else
			{
				cur->l->r=cur->r;
				cur->r->l=cur->l;
				cur=cur->r;
			}
		}
		else cur=cur->r;
	}
	if(pool[0].r==&pool[top+1])
	{
		printf("0\n");
		return 0;
	}
	//cout<<"QwQ\n";
	node *l=pool[0].r,*r=pool[top+1].l;
	while(l!=r)
	{
		//cout<<l->val<<' '<<l->len<<','<<r->val<<' '<<r->len<<endl;
		if(l->val==r->val)
		{
			if(l->len+r->len>=k)
			{
				ans+=m-1;ans2++;
				if(l->len+r->len>k)break;
				else l=l->r,r=r->l;
			}
			else break;
		}
		else break;
	}
	//cout<<"QwQ\n";
	if(l==r)
	{
		long long tmp=l->len;
		tmp*=m;
		ans+=tmp/k;
		tmp%=k;
		if(tmp==0)
		{
			ans+=ans2;
		}
	}
	printf("%lld\n",1ll*n*m-ans*k);
	return 0;
}