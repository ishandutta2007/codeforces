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
#include<ctime>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int num[10000010],z=0,lch[10000010],rch[10000010];
int insert(int i,int l,int r,int j)
{
	z++;
	int o=z;
	num[o]=num[i]+1;
	lch[o]=lch[i];
	rch[o]=rch[i];
	if(l==r)
		return o;
	int mid=(l+r)>>1;
	if(j>mid)
		rch[o]=insert(rch[i],mid+1,r,j);
	else
		lch[o]=insert(lch[i],l,mid,j);
	return o;
}
int get(int i,int l,int r,int x,int y)
{
	if(l==x&&r==y)
		return num[i];
	int mid=(l+r)>>1;
	if(x>mid)
		return get(rch[i],mid+1,r,x,y);
	else
		if(y<=mid)
			return get(lch[i],l,mid,x,y);
		else
			return get(lch[i],l,mid,x,mid)+get(rch[i],mid+1,r,mid+1,y);
}
int root[200010];
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int t1;
		scanf("%d",&t1);
		root[i]=insert(root[i-1],1,n,t1);
	}
	while(q--)
	{
		int t1,t2,t3,t4;
		scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		long long ans=n*1ll*(n-1)/2;
		ans-=(t1-1)*1ll*(t1-2)/2;
		ans-=(n-t3)*1ll*(n-t3-1)/2;
		ans-=(t2-1)*1ll*(t2-2)/2;
		ans-=(n-t4)*1ll*(n-t4-1)/2;
		int x;
		if(t2!=1)
		{
			x=get(root[t1-1],1,n,1,t2-1);
			ans+=x*1ll*(x-1)/2;
		}
		if(t4!=n)
		{
			x=get(root[t1-1],1,n,t4+1,n);
			ans+=x*1ll*(x-1)/2;
		}
		if(t2!=1)
		{
			x=get(root[n],1,n,1,t2-1)-get(root[t3],1,n,1,t2-1);
			ans+=x*1ll*(x-1)/2;
		}
		if(t4!=n)
		{
			x=get(root[n],1,n,t4+1,n)-get(root[t3],1,n,t4+1,n);
			//cout<<x<<endl;
			//cout<<get(root[n],1,n,1,n)<<endl;
			ans+=x*1ll*(x-1)/2;
		}		
		printf("%I64d\n",ans);
	}
		
}