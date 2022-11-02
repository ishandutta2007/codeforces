#include<cstdio>

using namespace std;

long long ans,n,m,l;

int main()
{
	scanf("%I64d%I64d",&n,&m);
	l=(n+1)/2;
	if(m<=l)ans=2*(m-1)+1;
	else ans=(m-l)*2;
	printf("%I64d",ans);
}