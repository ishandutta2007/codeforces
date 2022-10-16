#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,d,r,cnt;
double xi,yi,ri,dis;
int main()
{
	scanf("%d%d%d",&r,&d,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&xi,&yi,&ri);
		dis=sqrt((xi*xi)+(yi*yi));
		if(dis-ri>=r-d&&dis+ri<=r)cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}