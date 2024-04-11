#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
long long l,r,x,y,k;
double a,b;
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&l,&r,&x,&y,&k);
	for(int i=x;i<=y;i++)
	{
		if(k*i>=l&&k*i<=r)return printf("YES\n"),0;
	}
	printf("NO\n");
	return 0;
}