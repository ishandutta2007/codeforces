#include <cstdio>
#include <cstdlib>
using namespace std;
int m,n,i,j,l,r,mid,z;
int ls[60]; 
int main()
{
	scanf("%d%d",&m,&n);
	for (i=1;i<=n;i++)
	{
		printf("%d\n",1);
		fflush(stdout);
		scanf("%d",&j);
		if (j==0)
			exit(0);
		ls[i]=j==-1?-1:1;
	}
	l=2;
	r=m;
	z=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		printf("%d\n",mid);
		fflush(stdout);
		scanf("%d",&j);
		z++;
		j*=ls[(z-1)%n+1];
		if (j==0)
			exit(0);
		if (j==1)
			l=mid+1;
		else
			r=mid-1;
	}
	return 0;
}