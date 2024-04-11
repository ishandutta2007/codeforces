#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
	int c,p,id;
}a[10001];

struct lnm{
	int k,id;
}a1[10001];

int n,m,ans,b[10001],ans1[10001],ans2[10001],o;

int cmp(lhy a,lhy b)
{
	if(a.p!=b.p)return a.p>b.p;
	return a.c<b.c;
}

int cmp1(lnm a,lnm b)
{
	return a.k<b.k;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].c,&a[i].p);
		a[i].id=i;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a1[i].k),a1[i].id=i;
	sort(a+1,a+n+1,cmp);
	sort(a1+1,a1+m+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		int bo=0;
		for(int j=1;j<=m;j++)
		if(!b[j]&&a1[j].k>=a[i].c)
		{
			b[j]=1;
			ans+=a[i].p;
			ans1[++o]=a[i].id;
			ans2[o]=a1[j].id;
			break;
		}
	}
	printf("%d %d\n",o,ans);
	for(int i=1;i<=o;i++)
		printf("%d %d\n",ans1[i],ans2[i]);
}