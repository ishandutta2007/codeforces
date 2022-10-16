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
int n,ans,f[1<<18][19];
string s,ss;
vector<pair<int,int>> v;
signed main()
{
	n=read();
	cin>>s;
	for(int i=0;i<(1<<n);i++)
		f[i][0]=s[i]-'a'; 
	for(int i=1;i<=n;i++)
	{
		v.clear();
		for(int l=0;l<(1<<n);l++)
			v.push_back({f[l][i-1]*((1<<n)+1)+f[l^(1<<(i-1))][i-1],l});
		sort(ALL(v));
		f[v[0].second][i]=1;
		for(int l=1;l<(1<<n);l++)
		{
			f[v[l].second][i]=f[v[l-1].second][i];
			if(v[l].first!=v[l-1].first)
				f[v[l].second][i]++;
		}
		if(i==n)
			ans=v[0].second;
	}
	for(int i=0;i<(1<<n);i++)
		cout<<s[i^ans];
	return 0;
}