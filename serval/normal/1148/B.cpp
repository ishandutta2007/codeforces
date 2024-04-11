#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2e5+5;
int n,m,ta,tb,k;
int a[N],b[N];
int ans,cur,pos;
void upd(int v)
{
	if (ans!=-1)
		if (v>ans)
			ans=v;
	if (v==-1)
		ans=-1;
}
int main()
{
	ans=0;
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for (int i=0;i<=k;i++)
	{
		if (i>=n)
		{
			upd(-1);
			continue;
		}
		pos=lower_bound(b+1,b+m+1,a[i+1]+ta)-b;
		if (pos+k-i>m)
		{
			upd(-1);
			continue;
		}
		upd(b[pos+k-i]+tb);
	}
	printf("%d\n",ans);
	return 0;
}