#include<stdio.h>
using namespace std;
bool flag=false;
long n,k,y;
int main()
{
	scanf("%ld%ld%ld",&y,&k,&n);
	for(long i=1;i*k<=n;i++)
	if(i*k>y){printf("%ld ",i*k-y);flag=true;}
	if(!flag)printf("-1");
	return 0;
}