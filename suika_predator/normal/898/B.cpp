#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int a,b;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<=10000000;i++)
	{
		if(i*a<=n)
		{
			if((n-(i*a))%b==0)
			{
				printf("YES\n%d %d\n",i,(n-(i*a))/b);
				return 0;
			}
		}
		else break;
	}
	printf("NO\n");
	return 0;
}