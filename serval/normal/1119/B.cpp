#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1005;
int n,h;
int a[N],b[N];
int l,r,mid;
bool check(int p)
{
	for (int i=1;i<=p;i++)
		b[i]=a[i];
	sort(b+1,b+p+1);
	int th=h;
	for (int i=p;i>=0;i-=2)
	{
		th-=b[i];
		if (th<0)
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&h);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	l=0;
	r=n;
	while (l<r)
	{
		mid=(l+r+1)>>1;
		if (check(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}