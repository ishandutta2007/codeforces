#include<cstdio>
using namespace std;

int n,m,x,k,cnt;

int main()
{
	scanf("%d%d",&n,&m);
	while (n--)
	{
		scanf("%d",&k);
		if (x<k) cnt++,x=m;
		x-=k;
	}
	printf("%d\n",cnt);
}