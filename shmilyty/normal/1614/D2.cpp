#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
//const int INF=4e18;
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
const int N=2e7;
int n,a[100001],p[N+1];
ll f[N+1];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		p[a[i]]++;
	}
	p[1]=n;
	for(int i=1;i<=N;i++)
		if(p[i])
			for(int l=2;l*l<=i;l++)
				if(i%l==0)
				{
					p[l]+=p[i];
					if(l*l!=i)
						p[i/l]+=p[i];
				}
	for(int i=N;i;i--)
		if(f[i]||p[i])
		{
			f[i]+=1ll*i*p[i];
			for(int l=1;l*l<=i;l++)
				if(i%l==0)
				{
					f[l]=max(f[l],f[i]-1ll*p[i]*l);
					f[i/l]=max(f[i/l],f[i]-1ll*p[i]*(i/l));
				}
		}
	cout<<f[1];
}
signed main()
{
	solve(); 
	return 0;
}