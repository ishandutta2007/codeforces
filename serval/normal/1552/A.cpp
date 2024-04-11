#include <cstdio>
#include <algorithm>
using namespace std;
const int N=50;
int t;
int n,ans;
char a[N],b[N];
void solve()
{
	scanf("%d",&n);
	scanf("%s",a+1);
	for (int i=1;i<=n;i++)
		b[i]=a[i];
	sort(a+1,a+n+1);
	ans=n;
	for (int i=1;i<=n;i++)
		if (a[i]==b[i])
			ans--;
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&t);
	while (t--)
		solve();
	return 0;
}