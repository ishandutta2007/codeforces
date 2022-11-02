#include<cstdio>
#include<algorithm>

using namespace std;

int i,j,n,a[100001],t,o,an[100001],v;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	v=1;
	while(v<a[n])v<<=1;
	while(v)
	{
		o=0;
		for(i=1;i<=n;i++)
		if(v&a[i])an[++o]=a[i];
		if(o==0){v>>=1;continue;}
		t=an[1];
		for(i=2;i<=o;i++)
		t&=an[i];
		if(t%v==0)
		{
			printf("%d\n",o);
			for(i=1;i<=o;i++)
			printf("%d ",an[i]);
			return 0;
		}
		v>>=1;
	}
	printf("%d\n",&n);
	for(i=1;i<=n;i++)
	printf("%d ",a[i]);
}