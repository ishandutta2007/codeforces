#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,U;
int e[233333];
double ans=-1.0;
int main()
{
	scanf("%d%d",&n,&U);
	for(int i=1;i<=n;i++)scanf("%d",&e[i]);
	int r=1;
	for(int i=1;i<=n;i++)
	{
		while(r<n&&e[r+1]<=e[i]+U)r++;
		if(r>i+1)ans=max(ans,1.0*(e[r]-e[i+1])/(e[r]-e[i]));
	}
	if(ans<0)printf("-1\n");
	else printf("%.10lf\n",ans);
	return 0;
}