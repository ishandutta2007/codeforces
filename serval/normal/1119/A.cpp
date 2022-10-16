#include <cstdio>
using namespace std;
const int N=300005;
int n;
int c[N];
int ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for (int i=1;i<=n;i++)
		if (c[i]!=c[1])
			if (i-1>ans)
				ans=i-1;
	for (int i=1;i<=n;i++)
		if (c[i]!=c[n])
			if (n-i>ans)
				ans=n-i;
	printf("%d\n",ans);
	return 0;
}