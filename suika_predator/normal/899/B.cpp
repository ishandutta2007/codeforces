#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;

int n,m;
int s[233]={0,
			31,28,31,30,31,30,31,31,30,31,30,31,
			31,28,31,30,31,30,31,31,30,31,30,31,
			31,29,31,30,31,30,31,31,30,31,30,31,
			31,28,31,30,31,30,31,31,30,31,30,31,
			31,28,31,30,31,30,31,31,30,31,30,31,
			31,28,31,30,31,30,31,31,30,31,30,31,
			31,28,31,30,31,30,31,31,30,31,30,31};
int t[233];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
	}
	for(int i=0;i<=60;i++)
	{
		int flag=1;
		for(int j=1;j<=n;j++)
		{
			if(s[i+j]!=t[j])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
	return 0;
}