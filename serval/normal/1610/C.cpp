#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2e5+5;
int T;
int n,l,r,m;
int a[N],b[N];
bool chk(int m)
{
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (a[i]>=m-cnt-1&&b[i]>=cnt)
			cnt++;
	return cnt>=m;
}
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	l=1;
	r=n;
	while (l<r)
	{
		m=(l+r+1)>>1;
		if (chk(m))
			l=m;
		else
			r=m-1;
	}
	printf("%d\n",r);
}
int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}