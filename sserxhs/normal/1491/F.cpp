#include <bits/stdc++.h>
using namespace std;
const int N=2e3+2;
int t,n,i,l,r,mid,j;
bool hv[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		memset(hv+1,0,n);
		for (i=1;i<n-1;i++)
		{
			printf("? 1 %d\n%d\n",i,i+1);
			for (j=1;j<=i;j++) printf("%d%c",j,j==i?10:32);
			fflush(stdout);scanf("%d",&l);if (l) break;
		}
		l=1;r=i++;
		while (l<r)
		{
			mid=l+r>>1;
			printf("? 1 %d\n%d\n",mid-l+1,i);
			for (j=l;j<=mid;j++) printf("%d%c",j,j==mid?10:32);
			fflush(stdout);scanf("%d",&j);if (j) r=mid; else l=mid+1;
		}hv[i]=hv[l]=1;
		for (j=i+1;j<=n;j++)
		{
			printf("? 1 1\n%d\n%d\n",i,j);
			fflush(stdout);scanf("%d",&l);if (l) hv[j]=1;
		}
		l=0;for (i=1;i<=n;i++) if (!hv[i]) ++l;
		printf("! %d",l);for (i=1;i<=n;i++) if (!hv[i]) printf(" %d",i);puts("");fflush(stdout);
	}
}