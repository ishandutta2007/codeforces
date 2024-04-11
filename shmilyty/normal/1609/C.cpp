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
int t,n,e,ans,p[1000001],a[200001],f1[200001],f2[200001];
vector<int> pri;
void solve()
{
	n=read();
	e=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		f1[i]=f2[i]=0;
	for(int i=1;i<=n;i++)
		if(a[i]==1)
			f1[i]=1+((i>e)?f1[i-e]:0);
	for(int i=n;i;i--)
		if(a[i]==1)
			f2[i]=1+((i+e<=n)?f2[i+e]:0);
	ans=0;
	for(int i=1;i<=n;i++)
		if(!p[a[i]])
		{
			int k1=1+((i>e)?f1[i-e]:0),k2=1+((i+e<=n)?f2[i+e]:0);
			ans+=k1*k2-1; 
		}
	cout<<ans<<endl;
}
signed main()
{
	p[1]=1;
	for(int i=2;i<=1e6;i++)
	{
		if(!p[i])
			pri.push_back(i);
		for(int l:pri)
		{
			if(l*i>1e6)
				break;
			p[l*i]=1;
			if(i%l==0)
				break;
		}
	}
	t=read();
	while(t--)
		solve();
	return 0;
}