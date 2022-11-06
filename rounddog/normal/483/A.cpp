#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

long long int l,r;

int main()
{
	scanf("%I64d%I64d",&l,&r);
	if (l%2) l++;
	if (r-l>1) printf("%I64d %I64d %I64d\n",l,l+1,l+2);
	else printf("-1\n");
	return 0;
}