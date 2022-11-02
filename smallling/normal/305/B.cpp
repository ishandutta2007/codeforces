#include<cstdio>

using namespace std;

long long n,i,j,p,q,l,o,a[1001];

int main()
{
	scanf("%I64d%I64d",&p,&q);
	if(q==0){printf("NO");return 0;}
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
	for(i=1;i<=n;i++)
	{
		if(q==0)
		{
			printf("NO");
			return 0;
		}
		if(p/q<a[i])
		{
			printf("NO");
			return 0;
		}
		l=p-q*a[i];
		p=q;
		q=l;
	}
	if(!q)printf("YES");
	else printf("NO");
}