#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int dp[35010][55];
multiset<int> s;
int tree[200010],bj[200010];
void change(int i,int l,int r,int x,int y,int j)
{
	if(l==x&&r==y)
	{
		tree[i]+=j;
		bj[i]+=j;
		return;
	}
	int mid=(l+r)>>1;
	if(x>mid)
		change(i*2+1,mid+1,r,x,y,j);
	else
		if(y<=mid)
			change(i*2,l,mid,x,y,j);
		else
		{
			change(i*2,l,mid,x,mid,j);
			change(i*2+1,mid+1,r,mid+1,y,j);
		}
	tree[i]=max(tree[i*2],tree[i*2+1])+bj[i];
}
int get(int i,int l,int r,int x,int y)
{
	if(l==x&&r==y)
		return tree[i];
	int mid=(l+r)>>1;
	if(x>mid)
		return get(i*2+1,mid+1,r,x,y)+bj[i];
	else
		if(y<=mid)
			return get(i*2,l,mid,x,y)+bj[i];
		else
			return max(get(i*2+1,mid+1,r,mid+1,y),get(i*2,l,mid,x,mid))+bj[i];
}
int num[50010],pre[50010],is[50010];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		pre[i]=is[num[i]];
		is[num[i]]=i;
	}
	for(int i=1;i<=k;i++)
	{
		memset(tree,0,sizeof(tree));
		memset(bj,0,sizeof(bj));
		for(int j=1;j<=n;j++)
			change(1,0,n,j,j,-inf);
		int now=0;
		for(int j=1;j<=n;j++)
		{
			change(1,0,n,j,j,dp[j][i-1]+inf);
			change(1,0,n,pre[j],j-1,1);
			dp[j][i]=get(1,0,n,0,j-1);
			//cout<<j<<' '<<i<<' '<<dp[j][i]<<endl;
		}
	}
	cout<<dp[n][k]<<endl;
}