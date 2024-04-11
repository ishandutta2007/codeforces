#include<bits/stdc++.h>
#define N 1003
using namespace std;
int n,k,k2,a[N];
long long sum;
priority_queue<int>q;
int main()
{
    scanf("%d%d%d",&n,&k,&k2),k+=k2;
    for(int i=0;i<n;i++)
	scanf("%d",a+i);
	for(int i=0;i<n;i++)
	scanf("%d",&k2),a[i]=abs(a[i]-k2),sum+=a[i];
	if(sum<=k)
	{printf("%d",k-sum&1);return 0;}
	for(int i=0;i<n;i++)q.push(a[i]);
	for(int i=0;i<k;i++)
	{
		k2=q.top(),q.pop();
		q.push(k2-1);
	}
	sum=0;
	while(!q.empty())
	{
		k2=q.top(),sum+=k2*(long long)k2;
		q.pop();
	}
	printf("%lld",sum);
}