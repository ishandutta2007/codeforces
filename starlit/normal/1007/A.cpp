#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
using namespace std;
int n,a[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	for(int i=0,j=0;i<n&&j<n;i++)
	{
		if(a[j]<a[i])ans++,j++;
	}
	printf("%d",ans);
}