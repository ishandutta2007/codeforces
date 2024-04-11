#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

int T,i,j,k;
long long a,b;

bool calc(long long a,long long b)
{
	if(a>b)swap(a,b);
	if(a==0)return false;
	bool f=calc(a,b%a);
	if(!f)return true;
	if(a%2)
	{
		if((b/a)%2)return false;
		else return true;
	}
	else
	{
		if(((b/a)%(a+1))%2==0)return true;
		else return false;
	}
}

int main()
{
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%I64d%I64d",&a,&b);
		if(calc(a,b))printf("First\n");
		else printf("Second\n");
	}
}