#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e5+5;
int n;
int a[N];
long long ans;
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=0;
	bool chk=0;
	for (int i=2;i<n;i++)
		chk|=(a[i]&1^1);
	int cnt=0,cnt2=0;
	for (int i=2;i<n;i++)
	{
		cnt+=(a[i]&1);
		cnt2+=(a[i]>1);
	}
	chk|=(cnt>=2&&cnt2>=1);
	if (!chk)
	{
		printf("-1\n");
		return;
	}
	for (int i=2;i<n;i++)
		ans+=a[i]+(a[i]&1);
	printf("%lld\n",ans/2);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}