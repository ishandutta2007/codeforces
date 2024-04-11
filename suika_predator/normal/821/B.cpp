#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int m,b;
long long ans;
int main()
{
	scanf("%d%d",&m,&b);
	for(int y=0;y<=b;y++)
	{
		long long x=b*m-m*y;
		ans=max(ans,(x+y)*(x+1)*(y+1)/2);
	}
	printf("%I64d",ans);
	return 0;
}