#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;
int n,m;
int a[233],ans=23333;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if(a[j]-a[i]<=m)ans=min(ans,n-(j-i+1));
	printf("%d\n",ans);
	return 0;
}