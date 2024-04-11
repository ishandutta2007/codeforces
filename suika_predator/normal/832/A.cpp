#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long n,m;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	if((n/m)%2)printf("YES\n");
	else printf("NO\n");
	return 0;
}