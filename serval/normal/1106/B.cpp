#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100005;
int n,m;
int a[N],c[N],p[N];
int t,d,l,cur;
long long ans;
bool cmp(int a,int b)
{
	if (c[a]!=c[b])
		return c[a]<c[b];
	return a<b;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	l=1;
	while (m--)
	{
		scanf("%d%d",&t,&d);
		cur=min(d,a[t]);
		ans=1ll*cur*c[t];
		d-=cur;
		a[t]-=cur;
		while (d&&l<=n)
		{
			while (l<=n&&!a[p[l]])
				l++;
			if (l>n)
				break;
			cur=min(d,a[p[l]]);
			ans+=1ll*cur*c[p[l]];
			d-=cur;
			a[p[l]]-=cur;
		}
		if (d)
			ans=0;
		printf("%lld\n",ans);
	}
	return 0;
}