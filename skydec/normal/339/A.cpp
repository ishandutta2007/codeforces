#include<stdio.h>
#include<cstring>
using namespace std;
char p[105];
long f[4];long tot=0;
int main()
{
	scanf("%s",p+1);
	for(long i=1;i<=strlen(p+1);i++)
	if(p[i]!='+')
	{
		f[p[i]-'0']++;
		tot++;
	}
	long p=1;
	for(long k=1;k<tot;)
	{
		while(f[p]&&k<tot)
		{
			printf("%ld+",p);
			k++;
			f[p]--;
		}
		if(!f[p])p++;
	}
	if(f[p])printf("%ld",p);
	else
	{
		if(!f[p])p++;
		if(!f[p])p++;
		printf("%ld",p);
	}
	//for(;;);
	return 0;
}