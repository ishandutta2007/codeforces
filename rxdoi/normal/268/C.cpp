#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",min(n,m)+1);
	for (int i=0;i<=min(n,m);i++) printf("%d %d\n",n-i,i);
}