#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,i,j,k,l,r,mid,ans,num[50];
char s[1005];

int main()
{
	scanf("%s",s+1);
	scanf("%d",&n);
	for(i=strlen(s+1);i;--i)++num[s[i]-'a'+1];
	l=1;r=strlen(s+1);
	while(l<=r)
	{
		mid=l+r>>1;
		k=0;
		for(i=1;i<=26;++i)k+=num[i]/mid+(num[i]%mid!=0);
		if(k<=n)ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(ans==0)printf("-1\n");
	else
	{
		printf("%d\n",ans);
		for(i=1;i<=26;++i)
		{
			for(j=num[i]/ans+(num[i]%ans>0);j;--j)printf("%c",'a'+i-1);
			n-=num[i]/ans+(num[i]%ans>0);
		}
		for(;n;--n)printf("a");
		printf("\n");
	}
}