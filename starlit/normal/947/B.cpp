#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,v[N],t[N],val[N],sum,loc;
long long s[N],add[N];
inline int fd(int l,int r,long long vv)
{
	int mid,ret;
	while(l<=r)
	{
		mid=l+r>>1;
		if(s[mid]>vv)ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",v+i);
	for(int i=1;i<=n;i++)
	scanf("%d",t+i),s[i]=s[i-1]+t[i];
	for(int i=1;i<=n;i++)
	{
		if(s[n]-s[i-1]<=v[i]){val[i]++;continue;}
		if(t[i]>=v[i]){add[i]+=v[i];continue;}
		val[i]++;
		loc=fd(i+1,n,s[i-1]+v[i]);
		val[loc]--,add[loc]+=v[i]-(s[loc-1]-s[i-1]);
	}
	for(int i=1;i<=n;i++)
	{
		sum+=val[i];
		printf("%lld ",sum*(long long)t[i]+add[i]);
	}
}