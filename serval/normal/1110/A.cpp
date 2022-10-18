#include <cstdio>
using namespace std;
const int N=100005;
int b,k,a[N],c,ans;
int main()
{
	scanf("%d%d",&b,&k);
	b&=1;
	c=1;
	for (int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	for (int i=k;i;i--)
	{
		ans^=c&a[i];
		c&=b;
	}
	printf(ans?"odd\n":"even\n");
	return 0;
}