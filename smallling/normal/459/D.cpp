#include<cstdio>
#include<map>

using namespace std;

map<int,int>sum;

int n,c[1000010],f[1000010],b[1000010],a[1000010];
long long ans;

inline long long ask(int x)
{
	long long nowans=0;
	for(int i=x;i<=n;i+=i&-i)nowans+=1ll*c[i];
	return nowans;
}

inline void add(int x)
{
	for(int i=x;i;i-=i&-i)c[i]++;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		f[i]=++sum[a[i]];
	sum.clear();
	for(int i=n;i;i--)
		b[i]=++sum[a[i]];
	for(int i=1;i<=n;i++)
	{
		ans+=ask(b[i]+1);
		add(f[i]);
	}
	printf("%I64d",ans);
}