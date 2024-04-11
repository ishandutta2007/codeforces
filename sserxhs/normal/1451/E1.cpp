#include <bits/stdc++.h>
using namespace std;
const int N=1<<16;
int a[N+10],b[N];
int n,i,x;
int main()
{
	scanf("%d",&n);
	for (i=2;i<=n;i++)
	{
		printf("XOR 1 %d\n",i);
		fflush(stdout);
		scanf("%d",a+i);
	}
	for (i=2;i<=n;i++) if (!a[i])
	{
		printf("OR 1 %d\n",i);
		fflush(stdout);
		scanf("%d",a+1);
		break;
	}
	if (i<=n)
	{
		printf("! %d",a[1]);
		for (i=2;i<=n;i++) printf(" %d",a[1]^a[i]);puts("");
		return 0;
	}
	for (i=2;i<=n;i++) if (b[a[i]])
	{
		printf("OR %d %d\n",b[a[i]],i);
		fflush(stdout);
		scanf("%d",&x);
		a[1]=x^a[i];
		printf("! %d",a[1]);
		for (i=2;i<=n;i++) printf(" %d",a[1]^a[i]);puts("");
		return 0;
	} else b[a[i]]=i;
	for (i=1;i<=n;i++) if (a[i]==1)
	{
		printf("OR 1 %d\n",i);
		fflush(stdout);
		scanf("%d",a+1);
		for (i=1;i<=n;i++) if (1^a[i]&1)
		{
			printf("OR 1 %d\n",i);
			fflush(stdout);
			scanf("%d",&x);
			a[1]=(a[1]>>1<<1)|(x&1);
			printf("! %d",a[1]);
			for (i=2;i<=n;i++) printf(" %d",a[1]^a[i]);puts("");
			return 0;
		}
	}
}