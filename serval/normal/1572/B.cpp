#include <cstdio>
using namespace std;
const int N=2e5+5;
int T;
int n;
int s[2];
int a[N];
int ans[N],cnt;
void move(int i)
{
	ans[++cnt]=i;
	a[i]=(a[i]^a[i+1]^a[i+2]);
	a[i+1]=a[i];
	a[i+2]=a[i];
}
void solve()
{
	scanf("%d",&n);
	s[0]=s[1]=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[a[i]]++;
	}
	if (s[1]&1)
	{
		printf("NO\n");
		return;
	}
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0)
			continue;
		int j=i;
		while (1)
		{
			while (j<=n-2&&a[j+1]==1&&a[j+2]==1)
				j+=2;
			if (j>n-2)
				break;
			move(j);
			if (a[j]==0)
				break;
		}
		if (a[j]==1)
			break;
		for (int k=j-2;k>=i;k-=2)
			move(k);
	}
	s[0]=s[1]=0;
	for (int i=1;i<=n;i++)
		s[a[i]]++;
	if (s[1]==n)
	{
		printf("NO\n");
		return;
	}
	for (int i=n;i;i-=2)
		if (a[i]==0)
		{
			for (int j=i;j<=n-2;j+=2)
				move(j);
			break;
		}
	printf("YES\n");
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
		printf("%d%c",ans[i]," \n"[i==cnt]);
}
int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}