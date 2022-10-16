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
const int mod=998244353;
int n,ans,num[25][20001],mn[26],f[1<<25];
signed main()
{
	n=read();
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(int l=0;l<s.size();l++)
			num[i][s[l]-'a']++;
	}
	for(int i=1;i<(1<<n);i++)
	{
		for(int l=0;l<26;l++)
			mn[l]=INF;
		for(int l=0;l<n;l++)
			if((i>>l)&1)
				for(int j=0;j<26;j++)
					mn[j]=min(mn[j],num[l][j]);
		if(__builtin_parity(i))
			f[i]=1;
		else
			f[i]=mod-1;
		for(int l=0;l<26;l++)
			(f[i]*=(mn[l]+1))%=mod;
	}
	for(int l=0;l<n;l++)
		for(int i=1;i<(1<<n);i++)
			if((i>>l)&1)
				(f[i]+=f[i^(1<<l)])%=mod;
	for(int i=1;i<(1<<n);i++)
	{
		int tmp=0;
		for(int l=0;l<n;l++)
			if((i>>l)&1)
				tmp+=l+1;
		tmp*=__builtin_popcount(i);
		ans^=tmp*f[i];
	}
	cout<<ans;
	return 0;
}