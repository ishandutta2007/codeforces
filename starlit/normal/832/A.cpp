#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
long long n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	if((n/k)&1)puts("YES");
	else puts("NO");
}