#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,n,k,v,a[5001],b[5001],f[5001],g[5001],p[5001][5001];
void emp(int x,int y)//y->x
{
	printf("1000000000 %lld %lld\n",y,x);
	a[x]+=a[y];
}
void solve()
{
	n=read();
	k=read();
	v=read();
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=a[i]%k;
		a[0]+=a[i];
	}
	if(a[0]<v)
	{
		puts("NO");
		return ;
	}
	if(v%k==0)
	{
		puts("YES");
		for(int i=2;i<=n;i++)
			emp(1,i);
		if(v)
			printf("%lld %lld %lld\n",v/k,1,2);
		return ;
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int l=0;l<=k;l++)
			if(f[l])
			{
				g[l]=g[(l+b[i])%k]=1;
				p[i][l]=p[i][(l+b[i])%k]=l;
			}
		for(int l=0;l<=k;l++)
			f[l]=g[l];
	}
	if(f[v%k])
	{
		puts("YES");
		int tot=v%k,r1=0,r2=0;
		for(int i=n;i;i--)
		{
			b[i]=(tot!=p[i][tot]);
			tot=p[i][tot];
		}
		for(int i=1;i<=n;i++)
			if(a[i])
			{
				if(b[i])
				{
					if(r1)
						emp(r1,i);
					else
						r1=i;
				}
				else
				{
					if(r2)
						emp(r2,i);
					else
						r2=i;
				}
			}
		if(!r1)
			return ;
		if(a[r1]>v)
			printf("%lld %lld %lld\n",(a[r1]-v)/k,r1,(r1)%n+1);
		if(a[r1]<v)
			printf("%lld %lld %lld\n",(v-a[r1])/k,r2,r1);
		return ;
	}
	puts("NO");
}
signed main()
{
	t=1;
	while(t--)
		solve();
	return 0;
}