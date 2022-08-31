#include <cstdio>
#include <cstring>

char s1[112345];
char s2[112345];

int main()
{
	scanf("%s %s",s1,s2);
	int c4 = 0 , c7 = 0;
	for(int i=0;i<strlen(s1);i++)
		if(s1[i]!=s2[i]) if(s1[i]=='4') c4++; else c7++;
	printf("%d\n",c4>c7?c4:c7);
	return 0;
}