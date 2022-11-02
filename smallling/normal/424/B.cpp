#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

struct lhy{
	int k;
	double l;
}a[1100];

int n,num,x,y,i;

inline int cmp(lhy a,lhy b)
{
	return a.l<b.l;
}

int main()
{
	scanf("%d%d",&n,&num);
	num=1000000-num;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&a[i].k);
		a[i].l=sqrt(x*x+y*y);
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++)
	{
		num-=a[i].k;
		if(num<=0)break;
	}
	if(num>0)printf("-1");
	else
	printf("%.7lf",a[i].l);
}