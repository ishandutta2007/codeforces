#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,flag;
long long sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		if(m%2)flag=1;
		sum+=m;
	}
	if(sum%2)printf("First\n");
	else if(flag)printf("First\n");
	else printf("Second\n");
	return 0;
}