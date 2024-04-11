#include<cstdio>

using namespace std;

int n,a[1000001],ans,b[1000001],p,now;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),ans^=a[i];
	p=1;
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]^i;
	for(int i=2;i<=n;i++)
	{
		int o=n/i;
		if(o%2)now=b[i-1];
		else now=0;
		now^=b[(n%i)];
		ans^=now;
	}
	printf("%d",ans);
}