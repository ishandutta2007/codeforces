#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int n,ans,a[200001],b[200001],c[200001];
vector<int> v,u;
void solve()
{
	n=read();
	for(int i=0;i<n;i++)
		c[i]=b[i]=-1;
	v.clear();
	u.clear();
	ans=0;
	for(int i=0;i<n;i++)
	{
		a[i]=read()-1;
		if(c[a[i]]<0)
		{
			c[a[i]]=i;
			b[i]=a[i];
			ans++;
		}
	}
	for(int i=0;i<n;i++)
		if(c[i]==-1)
		{
			int l=i;
			while(b[l]>=0)
				l=b[l];
			u.push_back(i);
			v.push_back(l);
		}
	if(!u.empty())
	{
		if(u.size()>1||u[0]!=v[0])
		{
			for(int i=0;i<u.size();i++)
				b[v[i]]=u[(i+1)%u.size()];
		}
		else
		{
			int x=u[0];
			int y=a[x];
			b[x]=y;
			b[c[y]]=x;
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
		cout<<b[i]+1<<" ";
	cout<<endl;
	
}
signed main()
{
	int t=read();
	while(t--)
		solve();
	return 0;
}