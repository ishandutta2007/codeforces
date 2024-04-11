#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,i,j,k;
int fail[1000005];
char s[1000005];
bool f[1000005];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=2;i<=n;++i)
	{
		j=fail[i-1];
		while(j&&s[j+1]!=s[i])j=fail[j];
		if(s[j+1]==s[i])fail[i]=j+1;
	}
	for(i=2;i<n;++i)f[fail[i]]=true;
	for(i=fail[n];i;i=fail[i])
	if(f[i])
	{
		for(j=1;j<=i;++j)printf("%c",s[j]);
		return 0;
	}
	printf("Just a legend\n");
}