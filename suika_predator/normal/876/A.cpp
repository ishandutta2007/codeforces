#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a,b,c;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	if(n==1)return printf("0\n"),0;
	if(c<a&&c<b)return printf("%d\n",min(a,b)+c*(n-2)),0;
	if(a<b)return printf("%d\n",a*(n-1)),0;
	return printf("%d\n",b*(n-1)),0;
}