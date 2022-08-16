#include <cstdio>
#include <algorithm>
#define SI ({int x;scanf("%d",&x);x;})
using namespace std;

#define MXN 100005

int back[MXN], a[MXN];

int main()
{
	int n = SI, i, p = 0, s = 0;
	
	for(i=1;i<=n;i++) a[i]=SI;

	for(i=n;i>=1;i--)
	{
		s+=a[i];
		back[i]=max(-s,a[i]+back[i+1]);
	}

	int ans = back[1];

	for(i=1;i<=n;i++)
	{
		p+=a[i];
		ans = max( ans,-p+back[i+1] );
	}

	printf("%d\n",ans);

	return 0;
}