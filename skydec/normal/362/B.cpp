#include<stdio.h>
#include<algorithm>
using namespace std;
long data[4000];
long n,m;
int main()
{
	scanf("%ld%ld",&n,&m);
	for(long i=1;i<=m;i++)
	{
		scanf("%ld",&data[i]);
		if(data[i]==1||data[i]==n)
		{
			printf("NO\n");
			return 0;
		}
	}
	sort(data+1,data+1+m);
	for(long i=1;i<=m-2;i++)
	{
		if(data[i+2]-data[i]==2){printf("NO\n");return 0;}
	}
	printf("YES\n");
	return 0;
}