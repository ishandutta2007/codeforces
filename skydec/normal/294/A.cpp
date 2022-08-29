#include<stdio.h>
using namespace std;
long line[105];
long n,m;
int main()
{
	scanf("%ld",&n);
	for(long i=1;i<=n;i++)scanf("%ld",&line[i]);
	scanf("%ld",&m);
	for(long i=1;i<=m;i++)
	{
		long x,y;scanf("%ld%ld",&x,&y);
		line[x+1]+=line[x]-y;
		line[x-1]+=y-1;
		line[x]=0;
	}
	for(long i=1;i<=n;i++)printf("%ld\n",line[i]);
	return 0;
}