#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int a[]={0,4,6,10,15,21,27,33,39,43,46,48},d=49;
int s[233];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=11;i++)s[i]=s[i-1]+a[i];
	if(n<=11)printf("%d\n",s[n]);
	else printf("%lld\n",s[11]+1ll*d*(n-11));
	return 0;
}