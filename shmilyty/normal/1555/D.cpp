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
string s,dic[]={"abc","acb","bac","bca","cab","cba"};
int t,n,m,f[200001][3][3],qu[3][3];
void solve()
{
	cin>>s;
	n=s.size();
	int ans=INF;
	for(int i=0;i<6;i++)
	{
		int tot=0;
		for(int l=0;l<n;l++)
			if(s[l]!=dic[i][l%3])
				tot++;
		ans=min(ans,tot); 
	}
	cout<<ans<<endl;
}
signed main()
{
	n=read();
	m=read();
	cin>>s;
	for(int i=0;i<n;i++)
	{
		for(int l=0;l<3;l++)
			for(int j=0;j<3;j++)
				f[i+1][l][j]=f[i][l][j];
		f[i+1][i%3][s[i]-'a']++;
	}
	while(m--)
	{
		int l=read()-1,r=read();
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				qu[i][j]=f[r][i][j]-f[l][i][j];
		int ans=0;
		for(int i=0;i<6;i++)
		{
			int tot=0;
			for(int l=0;l<3;l++)
				tot+=qu[l][dic[i][l]-'a'];
			ans=max(ans,tot);
		}
		cout<<r-l-ans<<endl;
	}
	return 0;
}