#include <cstdio>
#include <algorithm>

using namespace std;

const int N=305;

int T;

int n,m;
int a[N],p[N];
long long ans;

bool cmp(int x,int y)
{
	if (a[x]!=a[y])
		return a[x]<a[y];
	return x>y;
}

void solve()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		p[i]=i;
	}
	sort(p+1,p+m+1,cmp);
	ans=0;
	for (int i=1;i<=m;i++)
		for (int j=1;j<i;j++)
			if (p[j]<p[i])
				ans++;
	printf("%lld\n",ans);
}

int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}