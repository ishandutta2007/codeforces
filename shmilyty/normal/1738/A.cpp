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
int T,n,ty[100001];
std::vector<int> v1,v2;
void solve()
{
	n=read();
	v1.clear();
	v2.clear();
	for(int i=1;i<=n;i++)
		ty[i]=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(ty[i]&1)
			v1.push_back(-x);
		else
			v2.push_back(-x);
	}
	sort(ALL(v1));
	sort(ALL(v2));
	int ans=0;
	if(!v1.empty())
	{
	int res=v1.back();
	int k=min(v1.size(),v2.size());
	// cout<<k<<'\n';
	for(int i=0;i<v1.size()-1;i++)
		if(i<k)
			res+=v1[i]*2;
		else
			res+=v1[i];
	for(int i=0;i<v2.size();i++)
		if(i<k)
			res+=v2[i]*2;
		else
			res+=v2[i];
	ans=-res;	
	}
	
	swap(v1,v2);
	if(!v1.empty())
	{
	int res=v1.back();
	int k=min(v1.size(),v2.size());
	// cout<<k<<'\n';
	for(int i=0;i<v1.size()-1;i++)
		if(i<k)
			res+=v1[i]*2;
		else
			res+=v1[i];
	for(int i=0;i<v2.size();i++)
		if(i<k)
			res+=v2[i]*2;
		else
			res+=v2[i];
	ans=max(ans,-res);
	}
	cout<<ans<<'\n';
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}