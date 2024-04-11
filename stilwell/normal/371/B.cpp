#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int a,b,i,j,k;
int ans,tmp;

int calc(int x)
{
	int res;
	res=0;
	while(x%2==0)x/=2,++res;
	while(x%3==0)x/=3,++res;
	while(x%5==0)x/=5,++res;
	if(x!=1)res=200000;
	return res;
}

void work(int x)
{
	if(b%x)return;
	tmp=0;
	tmp+=calc(a/x);
	tmp+=calc(b/x);
	if(tmp<ans)ans=tmp;
}

int main()
{
	scanf("%d%d",&a,&b);
	ans=100000;
	k=(int)sqrt(a);
	for(i=1;i<=k;++i)
	if(a%i==0)
	{
		work(i);
		work(a/i);
	}
	if(ans==100000)printf("-1\n");
	else printf("%d\n",ans);
}