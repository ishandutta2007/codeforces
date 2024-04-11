#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 2003
using namespace std;
int n,a[N],ans,tms;
bool now;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	for(int i=1;i<=n;i++)
	if(a[i]==1)tms++;
	if(tms)
	{printf("%d",n-tms);return 0;}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			a[j]=__gcd(a[j],a[j+1]);
			if(a[j]==1)return printf("%d",n-1+i),0;
		}
	}puts("-1");
}