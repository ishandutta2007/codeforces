#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace pb_ds
{
	int c1,c2,S1[200001],S2[200001],G1[200001],G2[200001];
	void clear()
	{
		c1=c2=0;
	}
	void push(int x)
	{
		S1[++c1]=x;
		G1[c1]=__gcd(G1[c1-1],x);
	}
	int query()
	{
		return __gcd(G1[c1],G2[c2]);
	}
	void pop()
	{
		if(!c2)
			for(;c1;c1--)
			{
				S2[++c2]=S1[c1];
				G2[c2]=__gcd(S1[c1],G2[c2-1]);
			}
		c2--;
	}
}
using namespace pb_ds;
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
int t,n,ans,a[200001],b[200001]; 
void solve()
{
	clear();
	int n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	n--;
	for(int i=1;i<=n;i++)
		b[i]=abs(a[i]-a[i+1]);
	int r=1;
	ans=1;
	for(int i=1;i<=n;i++)
	{
		while(r<=n&&query()!=1)
		{
			ans=max(ans,r-i+1);
			push(b[r]);
			r++;
		}
		if(query()!=1)
			ans=max(ans,r-i+1);
		pop();
	}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}