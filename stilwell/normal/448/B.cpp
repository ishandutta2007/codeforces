#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

char s1[100005],s2[100005];
int num[1005];
int l1,l2,i,j,k;
bool both;

int main()
{
	scanf("%s%s",s1+1,s2+1);
	l1=strlen(s1+1);
	l2=strlen(s2+1);
	k=1;
	for(i=1;i<=l1&&k<=l2;++i)
	if(s1[i]==s2[k])++k;
	if(k>l2){printf("automaton\n");return 0;}
	for(i=1;i<=l1;++i)++num[s1[i]];
	for(i=1;i<=l2;++i)--num[s2[i]];
	both=false;
	for(i=0;i<=1000;++i)
	{
		if(num[i]<0){printf("need tree\n");return 0;}
		if(num[i]>0)both=true;
	}
	if(both)printf("both\n");
	else printf("array\n");
}