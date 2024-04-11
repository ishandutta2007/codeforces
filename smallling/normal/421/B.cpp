#include<cstdio>
#include<cstring>

int n,l;
char s[100001];

int main()
{
	char ch=getchar();
	while(ch!='\n')s[++n]=ch,ch=getchar();
	for(int i=1;i<=n;i++)
	if(s[i]!='A'&&s[i]!='H'&&s[i]!='I'&&s[i]!='M'&&s[i]!='O'&&s[i]!='T'&&s[i]!='U'&&s[i]!='V'&&s[i]!='W'&&s[i]!='X'&&s[i]!='Y')
	{
		printf("NO");
		return 0;
	}
	for(int i=1;i<=n/2;i++)
	if(s[i]!=s[n-i+1])
	{
		printf("NO");
		return 0;
	}
	printf("YES");
}