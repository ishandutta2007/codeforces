#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;

int n,m;
int t,c1,c2,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(t==2)
		{
			if(c1)ans++,c1--;
			else c2++;
		}
		else
		{
			if(c2)ans++,c2--;
			else c1++;
		}
	}
	printf("%d\n",ans+c1/3);
	return 0;
}