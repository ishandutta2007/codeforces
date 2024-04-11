#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int n;
int a[2333],v[2333];
int d[2333];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d",&a[i+1]);
		v[a[i+1]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
			d[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==1&&d[i]<3)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}