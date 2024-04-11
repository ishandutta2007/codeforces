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
const int mod=1e9+7;
int n,ans,mul[10],ad[10];
string s,q[100001];
signed main()
{
	cin>>s;
	n=read();
	for(int i=1;i<=n;i++)
		cin>>q[i];
	for(int i=0;i<10;i++)
		mul[i]=10;
	for(int i=0;i<10;i++)
		ad[i]=i;
	for(int i=n;i;i--)
	{
		int x=q[i][0]-'0',na=0,nm=1;
		for(int l=3;l<q[i].size();l++)
		{
			int y=q[i][l]-'0';
			(nm*=mul[y])%=mod;
			(na*=mul[y])%=mod;
			(na+=ad[y])%=mod;
		}
		ad[x]=na;
		mul[x]=nm;
	}
	for(int i=0;i<s.size();i++)
		ans=(ans*mul[s[i]-'0']%mod+ad[s[i]-'0'])%mod;
	cout<<ans;
	return 0;
}