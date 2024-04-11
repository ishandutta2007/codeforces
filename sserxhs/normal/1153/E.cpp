#include <stdio.h>
int n,i,l,r,mid,x,xx,y,yy,z;
int main()
{
	scanf("%d",&n);
	for (i=1;i<n;i++)
	{
		printf("? 1 %d %d %d\n",i,n,i);
		fflush(stdout);scanf("%d",&z);
		if (z&1)
		{
			if (x) xx=i; else x=i;
		}
	}
	if ((x)&&(!xx)) xx=n;
	for (i=1;i<n;i++)
	{
		printf("? %d 1 %d %d\n",i,i,n);
		fflush(stdout);scanf("%d",&z);
		if (z&1)
		{
			if (y) yy=i; else y=i;
		}
	}
	if ((y)&&(!yy)) yy=n;
	if (x&&y)
	{
		printf("? %d %d %d %d\n",y,x,y,x);
		fflush(stdout);scanf("%d",&z);
		if (z&1) printf("! %d %d %d %d\n",y,x,yy,xx);
		else printf("! %d %d %d %d\n",y,xx,yy,x);
		fflush(stdout);return 0;
	}
	if (x)
	{
		l=1;r=n;
		while (l<r)
		{
			mid=l+r>>1;
			printf("? %d %d %d %d\n",l,x,mid,x);
			fflush(stdout);scanf("%d",&z);
			if (z&1) r=mid; else l=mid+1;
		}
		printf("! %d %d %d %d\n",l,x,l,xx);
		fflush(stdout);return 0;
	}
	l=1;r=n;
	while (l<r)
	{
		mid=l+r>>1;
		printf("? %d %d %d %d\n",y,l,y,mid);
		fflush(stdout);scanf("%d",&z);
		if (z&1) r=mid; else l=mid+1;
	}
	printf("! %d %d %d %d\n",y,l,yy,l);
	fflush(stdout);return 0;
}