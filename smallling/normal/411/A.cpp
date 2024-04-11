#include<cstdio>
#include<cstring>

using namespace std;

char s[1001];
int l,a1,a2,a3;

int main()
{
	scanf("%s",s+1);
	l=strlen(s+1);
	if(l<5){printf("Too weak");return 0;}
	for(int i=1;i<=l;i++)
	{
		if(s[i]<='Z'&&s[i]>='A')a1=1;
		if(s[i]<='z'&&s[i]>='a')a2=1;
		if(s[i]>='0'&&s[i]<='9')a3=1;
	}
	if(a1&&a2&&a3)printf("Correct");
	else printf("Too weak");
}