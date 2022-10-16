#include <cstdio>
using namespace std;
int n,y[1005],i,j,k;
double d,p1,p2;
bool f2,no;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&y[i]);
	for (i=2;i<=n;i++)
	{
		d=(y[i]-y[1])*1.0/(i-1);
		p1=y[1]-d;
		f2=0;
		no=0;
		for (j=1;j<=n;j++)
			if (p1+j*d!=y[j])
				if (!f2)
				{
					f2=1;
					p2=y[j]-d*j;
				}
				else
					if (p2+j*d!=y[j])
					{
						no=1;
						break;
					}
		if (!f2)
			no=1;
		if (!no)
		{
			printf("Yes\n");
			return 0;
		}
	}
	d=y[3]-y[2];
	p1=y[2]-d-d;
	if (y[1]!=y[2]-d)
	{
		no=0;
		for (i=2;i<=n;i++)
			if (p1+i*d!=y[i])
			{
				no=1;
				break;
			}
		if (!no)
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}