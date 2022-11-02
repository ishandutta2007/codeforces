#include <stdio.h>
#include <stdlib.h>
using namespace std;

int L[100001],Lmax;
int a[100001];
int l,r,mid,aim;
int n,m,i,j,k;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	{
		l=0;r=Lmax;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(a[i]>=L[mid])aim=mid,l=mid+1;
			else r=mid-1;
		}
		if(aim==Lmax)
		{
			++Lmax;
			L[aim+1]=a[i];
		}
		else if(a[i]<L[aim+1])L[aim+1]=a[i];
	}
	printf("%d\n",Lmax);
}