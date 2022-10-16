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
const int maxn=2e5; 
int ans,cnt,a[maxn],n,m;
multiset<int,greater<int>>s;
struct dsu{
	int fa[maxn],sz[maxn];
	void init(int k)
	{
		for(int i=1;i<=k;i++)
		{
			fa[i]=i;
			s.insert(1);
			sz[i]=1;	
		}
	}
	int find(int k)
	{
		return k==fa[k]?k:fa[k]=find(fa[k]);
	}
	bool merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x!=y)
		{
			if(sz[x]>sz[y])
				swap(x,y);
			s.erase(s.find(sz[x]));
			s.erase(s.find(sz[y]));
			fa[x]=y;
			sz[y]+=sz[x];
			ans=max(ans,sz[y]-1);
			s.insert(sz[y]);
			return 1;
		}
		return 0;
	}
}res;
signed main()
{
	n=read();
	m=read();
	res.init(n);
	while(m--)
	{
		int x=read(),y=read();
		if(!res.merge(x,y))
			cnt++;
		auto it=++s.begin();
		int sum=0;
		for(int i=1;i<=cnt;i++)
			if(it!=s.end())
			{
				sum+=(*it);
				it++;
			}	
		cout<<ans+sum<<endl;
	}
	return 0;
}