#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2e5+5;
int T;
int n;
int a[N],p[N];
int len;
int get(int b)
{
	int c=0;
	p[++c]=b;
	if (b+1<=n)
		p[++c]=b+1;
	else
		return c;
	while (p[c]<n)
	{
		int q=lower_bound(a+1,a+n+1,2*a[p[c]]-a[p[1]])-a;
		if (q<=p[c])
			q=p[c]+1;
		if (q>n)
			break;
		p[++c]=q;
	}
	return c;
}
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	len=0;
	for (int i=1;i<=n;i++)
		if (a[i]!=a[i-1])
			len=max(len,get(i));
	printf("%d\n",n-len);
}
int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}