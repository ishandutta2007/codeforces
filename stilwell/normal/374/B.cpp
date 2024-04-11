#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

char s[100005];
int i,j,k,tot,l;
long long ans;

int main()
{
	scanf("%s",s+1);
	l=strlen(s+1);
	tot=1;ans=1;
	for(i=2;i<=l;++i)
	if(s[i]+s[i-1]-'0'-'0'==9)++tot;
	else
	{
		if(tot%2==1)ans=ans*(tot+1)/2;
		tot=1;
	}
	if(tot%2==1)ans=ans*(tot+1)/2;
	printf("%I64d\n",ans);
}