#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
// #define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
// const int INF=4e18;
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
string s;
int n,f[2000001][26],fail[2000001];
signed main()
{
	cin>>s;
	f[0][s[0]-'a']=1;
	fail[0]=1;
	for(int i=1;i<s.size();i++)
	{
		for(int l=0;l<26;l++)
			if(s[i]-'a'==l)
			{
				f[i][l]=i+1;
				fail[i+1]=f[fail[i]][l];
			}
			else
				f[i][l]=f[fail[i]][l];
	}
	n=read();
	while(n--)
	{
		string ss;
		cin>>ss;
		for(int i=s.size();i<ss.size()+s.size();i++)
		{
			for(int l=0;l<26;l++)
				if(ss[i-s.size()]-'a'==l)
				{
					f[i][l]=i+1;
					fail[i+1]=f[fail[i]][l];
				}
				else
					f[i][l]=f[fail[i]][l];
			cout<<fail[i+1]<<" \n"[i==ss.size()+s.size()-1];
		}
	}
	return 0;
}