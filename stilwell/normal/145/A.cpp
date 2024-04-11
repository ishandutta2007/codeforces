#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,n1,n2,i;
char s1[100005],s2[100005];

int main()
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	for(i=1;i<=n;++i)
	if(s1[i]!=s2[i])
	{
		if(s1[i]=='4')++n1;else ++n2;
	}
	printf("%d\n",max(n1,n2));
}