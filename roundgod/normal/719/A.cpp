#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 92
using namespace std;
int n,a[MAXN];
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		scanf("%d",&a[0]);
		if(a[0]==0) printf("UP");
		else if(a[0]==15) printf("DOWN");
		else printf("-1");
	}
	else
	{
		for(int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		if(a[n-1]==0) printf("UP");
		else if(a[n-1]==15) printf("DOWN");
		else if(a[n-2]>a[n-1]) printf("DOWN");
		else if(a[n-2]<a[n-1]) printf("UP");
	}
	return 0;
}