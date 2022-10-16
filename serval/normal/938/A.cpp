#include <cstdio>
using namespace std;
char s[500];
int n,i,r;
bool c(char p)
{
	return p=='a'||p=='e'||p=='i'||p=='o'||p=='u'||p=='y';
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%c",&s[i]);
		while (s[i]<'a'||s[i]>'z')
			scanf("%c",&s[i]);
	}
	for (i=1;i<=n;i++)
	{
		if (c(s[i])&&c(s[i-1]))
			continue;
		printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}