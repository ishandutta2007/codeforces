#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

long long l,r,mid,tmp,ans,a,b,c,na,nb,nc,pa,pb,pc,sum,ta,tb,tc;
int i,j,k;
char s[10001];

int main()
{
	scanf("%s",s+1);
	k=strlen(s+1);
	for(i=1;i<=k;++i)
	{
		if(s[i]=='B')++a;
		if(s[i]=='S')++b;
		if(s[i]=='C')++c;
	}
	scanf("%I64d%I64d%I64d",&na,&nb,&nc);
	scanf("%I64d%I64d%I64d",&pa,&pb,&pc);
	scanf("%I64d",&sum);
	ans=0;
	l=0;r=10000000000000LL;
	while(l<=r)
	{
		mid=(l+r)/2;
		ta=mid*a-na;
		tb=mid*b-nb;
		tc=mid*c-nc;
		if(ta<0)ta=0;
		if(tb<0)tb=0;
		if(tc<0)tc=0;
		tmp=ta*pa+tb*pb+tc*pc;
		if(tmp>sum)r=mid-1;
		else l=mid+1,ans=mid;
	}
	printf("%I64d\n",ans);
}