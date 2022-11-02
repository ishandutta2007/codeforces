#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

long long n,m,K,i,j,k,ans;
long long l,r,mid1,mid2,ansl,ansr,ans1,ans2;

void check(long long a)
{
	long long b=K-a;
	if(a>=n)return;if(a<0)return;
	if(b>=m)return;if(b<0)return;
	long long x,y;
	if((n/(a+1))*(m/(b+1))>ans)ans=(n/(a+1))*(m/(b+1));
}

int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&K);
	if(K>n+m-2){printf("-1\n");return 0;}
	ans=-1;
	check(0);check(K);
	check(n-1);check(K-m+1);
	printf("%I64d\n",ans);
}