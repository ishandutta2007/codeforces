#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int sum(int x)
{
	int ret=0;
	while(x)ret+=x%10,x/=10;
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i;i++)
	{
		if(sum(i)==10)m++;
		if(m==n)
		{
			return printf("%d\n",i),0;
		}
	}
	return 0;
}