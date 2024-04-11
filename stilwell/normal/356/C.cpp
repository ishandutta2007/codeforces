#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k,a1,a2,a3,a4,ans;

int main()
{
	scanf("%d",&n);
	for(;n;--n)
	{
		scanf("%d",&k);
		if(k==1)++a1;if(k==2)++a2;
		if(k==3)++a3;if(k==4)++a4;
	}
	ans=min(a1,a2);
	a1-=ans;a2-=ans;a3+=ans;
	if(a1)
	{
		ans+=a1/3*2;
		a3+=a1/3;
		a1%=3;
		if(a4&&a1==2)ans+=2,a3+=2,a1=0,--a4;
		if(a3>=a1)ans+=a1,a4+=a1,a3-=a1,a1=0;
		if(a1==1&&a4>=2)ans+=2,--a1,a3+=3,a4-=2;
		if(a1){printf("-1\n");return 0;}
	}
	if(a2)
	{
		ans+=a2/3*2;
		a3+=a2/3*2;
		a2%=3;
		if(a2==2)ans+=2,++a4,a2=0;
		if(a2==1&&a4)++ans,--a4,--a2,a3+=2;
		if(a2==1&&a3>=2)ans+=2,--a2,a3-=2,a4+=2;
		if(a2){printf("-1\n");return 0;}
	}
	printf("%d\n",ans);
}