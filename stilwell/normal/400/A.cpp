#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,i,j,k;
char s[15];
bool w[15],ans[15];

int main()
{
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%s",s+1);
		for(i=1;i<=12;++i)ans[i]=false;
		for(i=1;i<=12;++i)
		if(12%i==0)
		{
			for(j=0;j<i;++j)w[j]=true;
			for(j=1;j<=12;++j)if(s[j]=='O')w[j%i]=false;
			for(j=0;j<i;++j)if(w[j])ans[12/i]=true;
		}
		k=0;
		for(i=1;i<=12;++i)if(ans[i])++k;
		printf("%d",k);
		for(i=1;i<=12;++i)if(ans[i]&&12%i==0)printf(" %dx%d",i,12/i);
		printf("\n");
	}
}