#include<bits/stdc++.h>
using namespace std;
struct node
{
	node *lson,*rson;
	int l,r,minn,lazy;
	inline void mark(int x){lazy+=x;minn+=x;}
	inline void upd(){minn=min(lson->minn,rson->minn);}
	inline void push(){if(lazy){lson->mark(lazy);rson->mark(lazy);lazy=0;}}
}*root,pool[233333];
int top;
node *build(int l,int r)
{
	node *tmp=&pool[top++];
	tmp->minn=tmp->lazy=0;tmp->l=l;tmp->r=r;
	if(l!=r)
	{
		int mid=(l+r)/2;
		tmp->lson=build(l,mid);
		tmp->rson=build(mid+1,r);
	}
	else tmp->lson=tmp->rson=0;
	return tmp;
}
void change(node *cur,int l,int r,int val)
{
	if(cur->l==l&&cur->r==r)
	{
		cur->mark(val);
		return;
	}
	cur->push();
	if(cur->lson->r>=r)change(cur->lson,l,r,val);
	else if(cur->rson->l<=l) change(cur->rson,l,r,val);
	else change(cur->lson,l,cur->lson->r,val),change(cur->rson,cur->rson->l,r,val);
	cur->upd();
}
int query(node *cur,int l,int r)
{
	if(cur->l==l&&cur->r==r)
	{
		return cur->minn;
	}
	cur->push();
	if(cur->lson->r>=r)return query(cur->lson,l,r);
	else if(cur->rson->l<=l)return query(cur->rson,l,r);
	else return min(query(cur->lson,l,cur->lson->r),query(cur->rson,cur->rson->l,r));
}
int dp[111][35555],nx[35555],pre[35555];
int n,k;
int a[35555],pos[35555];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(pos[a[i]])
		{
			pre[i]=pos[a[i]];
			nx[pos[a[i]]]=i;
		}
		pos[a[i]]=i;
	}
//	for(int i=1;i<=n;i++)cerr<<i<<' '<<pre[i]<<' '<<nx[i]<<endl;
	memset(dp[0],0x3f,sizeof(dp[0]));
	dp[0][0]=0;
	for(int t=1;t<=k;t++)
	{
		top=0;
		root=build(0,n);
		for(int i=0;i<=n;i++)
		{
			change(root,i,i,dp[t-1][i]);
			if(nx[i])
			{
				change(root,0,i-1,nx[i]-i);
			}
		}
		for(int i=n;i>=1;i--)
		{
			dp[t][i]=query(root,0,i-1);
			if(pre[i])
			{
				change(root,0,pre[i]-1,pre[i]-i);
			}
		}
	}
	cout<<dp[k][n]<<endl;
/*
	for(int t=0;t<=k;t++)
	{
		for(int i=0;i<=n;i++)
		{
			cerr<<t<<' '<<i<<' '<<dp[t][i]<<endl;
		}
	}
*/
	return 0;
}