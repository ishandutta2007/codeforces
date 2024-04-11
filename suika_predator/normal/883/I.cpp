#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=600010;
int n,k;
int a[MAXN],b[MAXN],s[MAXN];
inline bool check(int x)
{
	memset(b,0,sizeof(b));
	int l=1;
	b[0]=s[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i<k)
		{
			s[i]=s[i-1];
			continue;
		}
		while(l<=i-k+1&&a[l]<a[i]-x)l++;
		if(l!=1)b[i]=(s[i-k]-s[l-2]!=0);
		else b[i]=(s[i-k]!=0);
		s[i]=s[i-1]+b[i];
	}
	return (b[n]!=0);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=0,r=1e9+7;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}