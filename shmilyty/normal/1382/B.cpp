#include<bits/stdc++.h>
using namespace std;
int t,n,a,num,flag;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		num=flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(!flag||i==n)
				continue;
			if(a!=1)
				flag=0;
			else
				num^=1;
		}
		if(num)
			puts("First");
		else
			puts("Second");
	}
	return 0;
}