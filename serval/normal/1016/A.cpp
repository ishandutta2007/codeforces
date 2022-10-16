#include <cstdio>
using namespace std;
int n,i;
long long m,v,p;
int main()
{
	scanf("%d %I64d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&v);
		printf(i<n?"%I64d ":"%I64d\n",(v+p)/m);
		p=(v+p)%m;
	}
	return 0;
}