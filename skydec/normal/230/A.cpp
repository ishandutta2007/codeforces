#include<algorithm>
#include<stdio.h>
using namespace std;
struct dra
{
	long x,y;
}data[1005];
bool cmp(dra a,dra b){return a.x<b.x;}
long s,n;
int main()
{
	scanf("%ld%ld",&s,&n);
	for(long i=1;i<=n;i++)scanf("%ld%ld",&data[i].x,&data[i].y);
	sort(data+1,data+1+n,cmp);
	for(long i=1;i<=n;i++)
	{
		if(s>data[i].x)
		{
			s+=data[i].y;
		}
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}