#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
long long ans,now;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n&&i<9;i++)
	for(int j=0;i+j<=n&&j<9;j++)
	{
		ans+=n-(i+j)+1;
		if(i>4)break;
	}
	printf("%I64d",ans);
}