#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 100020

int ans[maxn],l,r,t,n,k,f;

int main()
{
	scanf("%d%d",&n,&k);
	l=n-k,r=n;
	for (int i=1;i<n-k;i++)
	    ans[i]=i;
	f=1;
	for (int i=n-k;i<=n;i++)
	{
	    if (f) ans[i]=l++; else ans[i]=r--;
	    f=1-f;
	}
	for (int i=1;i<n;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
}