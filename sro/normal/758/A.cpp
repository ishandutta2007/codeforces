#include <cstdio>
#include <iostream>
using namespace std;

int n,cnt=0;
int a[1234567],maxv=0;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxv)maxv=a[i];
	}
	for(int i=0;i<n;i++)
	{
		cnt+=maxv-a[i];
	}
	printf("%d",cnt);
	return 0;
}