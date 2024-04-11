#include <cstdio>
#include <algorithm>
using namespace std;
const int N=105;
int n;
int a[N],p[N],s,cur,pos;
bool cmp(int u,int v)
{
	return a[u]<a[v];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
		p[i]=i;
	}
	sort(p+2,p+n+1,cmp);
	cur=a[1];
	pos=2;
	while (pos<=n&&a[p[pos]]*2<=a[1])
	{
		cur+=a[p[pos]];
		pos++;
	}
	if (2*cur<=s)
		printf("0\n");
	else
	{
		printf("%d\n",pos-1);
		for (int i=1;i<=pos-1;i++)
			printf("%d ",p[i]);
		printf("\n");
	}
	return 0;
}