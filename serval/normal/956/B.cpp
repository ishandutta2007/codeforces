#include <cstdio>
using namespace std;
long long e[100005],u;
int n,i,j,k;
long long x,y;
bool exist;
int main()
{
	scanf("%d%I64d",&n,&u);
	for (i=1;i<=n;i++)
		scanf("%I64d",&e[i]);
	k=1;
	for (i=1;i<=n-2;i++)
	{
		while (e[k+1]-e[i]<=u&&k<n)
			k++;
		j=i+1;
		if (k>j)
			exist=1;
		if (k>j)
			if ((e[k]-e[j])*y>x*(e[k]-e[i])||y==0)
			{
				x=e[k]-e[j];
				y=e[k]-e[i];
			}
	}
	if (exist)
	{
		printf("0.");
		for (i=1;i<=500;i++)
		{
			x=x*10;
			printf("%I64d",x/y);
			x=x%y;
		}
	}
	else
		printf("-1\n");
	return 0;
}