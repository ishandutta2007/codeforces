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
int n,ans,f[1<<20];
string s;
signed main()
{
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int l=0;l<20&&i+l<n;l++)
		{
			int k=s[i+l]-'a';
			if((cnt>>k)&1)
				break;
			cnt^=(1<<k);
			f[cnt]=l+1;
		}
	}
	for(int i=0;i<(1<<20);i++)
		for(int l=0;l<20;l++)
			if((i>>l)&1)
				f[i]=max(f[i],f[i-(1<<l)]);
	for(int i=0;i<(1<<20);i++)
		ans=max(ans,f[i]+f[(1<<20)-1-i]);
	cout<<ans;
	return 0;
}