#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,k;
long long sum;
struct atom
{
	int c,id;
	inline bool operator<(const atom &x)const{return c<x.c;}
}a[300010];
int ans[300010];
priority_queue<atom> pq;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].c);
		a[i].id=i;
	}
	int t=min(k,n);
	for(int i=1;i<=t;i++)
	{
		pq.push(a[i]);
	}
	for(int i=k+1;i<=n+k;i++)
	{
		if(i<=n)pq.push(a[i]);
		sum+=(long long)pq.top().c*(i-pq.top().id);
		ans[pq.top().id]=i;
		pq.pop();
	}
	printf("%I64d\n",sum);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}