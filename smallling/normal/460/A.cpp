#include<cstdio>

using namespace std;

int n,m,now,ans,last;

int main()
{
	scanf("%d%d",&n,&m);
	while(n)
	{
		ans+=n;
		now=n;
		n=(n+last)/m;
		last=(now+last)%m;
	}
	printf("%d",ans);
}