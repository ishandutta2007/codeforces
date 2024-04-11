#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
	{
	int a[25000],n;
	scanf("%d",&n);
	int i,j,t;
	for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		}
	//sort(a,a+n);
	int s=0;
	int mx=-100000000;
	for(i=1;i<=n/3;i++)
		{
		if(n%i==0)
			{
			for(j=0;j<i;j++)
				{
				s=0;
				for(t=j;t<n;t+=i)
					{
					if(t<n)s+=a[t];
					}
				//printf("%d %d  %d\n",i,j,s);
				if(mx<s)
					{
					mx=s;
					}
				}
			}
		}
	printf("%d\n",mx);
	//system("pause");
	return 0;
	}