#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int n,add,rnd,mx,a[100001][36],b[100001],c[100001],vis[100001],ans[100001];
set<int> s;
vector<int> bel[100001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i][0]=read();
		if(vis[a[i][0]])
			add++;
		vis[a[i][0]]=1;
	}
	for(int i=1;i<=n;i++)
		mx=max(mx,b[i]=read());
	rnd=(mx-n)/add;
	for(int i=1;i<=35;i++)
		for(int l=1;l<=n;l++)
			a[l][i]=a[a[l][i-1]][i-1];
	for(int i=1;i<=n;i++)
		c[i]=i;
	for(int i=35;~i;i--)
		if((rnd>>i)&1)
			for(int l=1;l<=n;l++)
				c[l]=a[c[l]][i];
	for(int i=1;i<=n;i++)
		bel[c[i]].push_back(i);
	for(int i=1;i<=n;i++)
		s.insert(i);
	for(int i=1;i<=n;i++)
		if(b[i]<=n)
		{
			int minn=INF;
			for(int l:bel[i])
				minn=min(minn,l);
			ans[minn]=b[i];
			s.erase(b[i]);
		}
	for(int i=1;i<=n;i++)
		if(!ans[i])
		{
			if(b[c[i]]<=n)
				ans[i]=*s.lower_bound(b[c[i]]);
			else
				ans[i]=*s.begin();
			s.erase(ans[i]);
		}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}