#include <cstdio>
#include <algorithm>
using namespace std;
const int N=3e5+5;
int n;
int a[N],b[N];
int gt,lt;
int v[N],p[N],c;
bool cmp(int a,int b)
{
	return v[a]<v[b];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if (a[i]<b[i])
			lt++;
		else
			gt++;
	}
	if (lt>gt)
	{
		printf("%d\n",lt);
		for (int i=1;i<=n;i++)
			if (a[i]<b[i])
			{
				v[i]=b[i];
				p[++c]=i;
			}
		sort(p+1,p+lt+1,cmp);
		for (int i=lt;i;i--)
			printf("%d ",p[i]);
		printf("\n");
	}
	else
	{
		printf("%d\n",gt);
		for (int i=1;i<=n;i++)
			if (a[i]>b[i])
			{
				v[i]=a[i];
				p[++c]=i;
			}
		sort(p+1,p+gt+1,cmp);
		for (int i=1;i<=gt;i++)
			printf("%d ",p[i]);
		printf("\n");
	}
	return 0;
}