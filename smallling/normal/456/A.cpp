#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
	int v,p;
}a[100010];

int n,Max;

inline int cmp(const lhy &a,const lhy &b)
{
	return a.p<b.p;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].p,&a[i].v);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(Max>a[i].v)
		{
			puts("Happy Alex");
			return 0;
		}
		Max=max(Max,a[i].v);
	}
	puts("Poor Alex");
}