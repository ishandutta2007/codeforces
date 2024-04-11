#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		cur*=2;
		if(cur>m)
		{
			printf("%d\n",m);
			return 0;
		}
	}
	printf("%d\n",m%cur);
	return 0;
}