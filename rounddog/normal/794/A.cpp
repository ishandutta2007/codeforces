#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

int a,b,c,n,ans,t;

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d",&n);
	ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if (t>b&&t<c) ans++;
	}
	printf("%d\n",ans);
	return 0;
}