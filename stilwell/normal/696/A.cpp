#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <algorithm>
using namespace std;

int n,m,i,j,k,opt;
long long u,v,c;

map <long long,long long> A;

int main()
{
	scanf("%d",&n);
	for(;n;--n)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%I64d%I64d%I64d",&u,&v,&c);
			for(;u!=v;)
			{
				if(u<v)swap(u,v);
				A[u]+=c;u/=2;
			}
		}
		else
		{
			scanf("%I64d%I64d",&u,&v);c=0;
			for(;u!=v;)
			{
				if(u<v)swap(u,v);
				c+=A[u];u/=2;
			}
			printf("%I64d\n",c);
		}
	}
}