#include<stdio.h>
#include<cstring>
using namespace std;
char p[35][25];long n;
bool find(long x)
{
	for(long i=1;i<=n;i++)
	for(long j=1;j<=strlen(p[i]+1);j++)
	{
		if(p[i][j]==x+'a'-1)return false;
	}
	return true;
}
bool find2(long x,long y)
{
	for(long i=1;i<=n;i++)
	for(long j=1;j<=strlen(p[i]+1)-1;j++)
	{
		if(p[i][j]==x+'a'-1&&p[i][j+1]==y+'a'-1)return false;
	}
	return true;
}
int main()
{
	scanf("%ld",&n);
	for(long i=1;i<=n;i++)scanf("%s",p[i]+1);
	for(long i=1;i<=26;i++)
	{
		if(find(i))
		{
			printf("%c",i+'a'-1);
			return 0;
		}
	}
	for(long i=1;i<=26;i++)
	for(long j=1;j<=26;j++)
	{
		if(find2(i,j))
		{
			printf("%c%c",i+'a'-1,j+'a'-1);
			return 0;
		}
	}
	return 0;
}