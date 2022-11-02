#include<cstdio>

using namespace std;

int n,m,minn,maxx,a[10001];

int main()
{
	scanf("%d%d%d%d",&n,&m,&minn,&maxx);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	int b=0;
	int b1=0;
	int b2=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i]>maxx||a[i]<minn)b=1;
		if(a[i]==maxx&&b1==0)b1=1;
		if(a[i]==minn&&b2==0)b2=1;
	}
	if(b1+b2+n-m>=2&&!b)printf("Correct");
	else printf("Incorrect");
}