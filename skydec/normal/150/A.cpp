#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
int main()
{
	LL q;scanf("%I64d",&q);
	int yors=0;LL x=q;LL ans=1;
	for(int i=2;i*1ll*i<=x;i++)
	while(x%i==0)
	{
		if(yors<2)ans*=i;
		x/=i,yors++;
	}
	if(x!=1)
	{
		if(yors<2)ans*=x;
		x=1,yors++;
	}
	if(yors<=1){printf("1\n0\n");return 0;}
	if(yors==2){printf("2\n");return 0;}
	printf("1\n%I64d\n",ans);
	return 0;
}