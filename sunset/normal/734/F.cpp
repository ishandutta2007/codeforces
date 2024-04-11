#include<bits/stdc++.h>

using namespace std;

const int maxn=200010;

int a[maxn],b[maxn],c[maxn],d[maxn],e[maxn],table[32],cnt[32],n;

int s[maxn];

long long tot;

inline bool chk()
{
	table[0]=1;
	for(int i=1;i<=31;i++) table[i]=table[i-1]<<1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=31;j++)
			if(a[i]&table[j])
				cnt[j]++;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=31;j++)
			if(a[i]&table[j])
				d[i]+=1ll*table[j]*cnt[j],e[i]+=1ll*table[j]*n;
			else
				e[i]+=1ll*table[j]*cnt[j];
	for(int i=1;i<=n;i++)
		if(b[i]!=d[i]||c[i]!=e[i])
			return false;
	return true;
}

int main()
{
//	freopen("problem.in","r",stdin);
//	freopen("problem.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		s[i]=b[i]+c[i],tot+=s[i];
	if(tot%(2*n))
	{
		printf("-1\n");
		return 0;
	}
	tot/=(2*n);
	for(int i=1;i<=n;i++)
	{
		if((s[i]-tot)%n)
		{
			printf("-1\n");
			return 0;
		}
		a[i]=(s[i]-tot)/n;
	}
	if(chk())
	{
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		putchar(10);
		return 0;
	}
	else
	{
		printf("-1\n");
		return 0;
	}
}