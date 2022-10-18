#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=1e2+2;
int a[N];
int i,t,n,j,c;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d",a+i);j=1;
		for (i=2;i<=n;i++) if (a[i]>a[j]) j=i;c=0;
		for (i=1;i<=n;i++) if (i!=j) c+=a[i];
		if (a[j]<=c)
		{
			if ((c^a[j])&1) puts("T"); else puts("HL");
			continue;
		}
		puts("T");
	}
}