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
int n,m,q,wa[1000001];
string s[1000001];
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]=" "+s[i];
	}
	for(int l=2;l<=m;l++)
		for(int i=2;i<=n;i++)
			if(s[i-1][l]=='X'&&s[i][l-1]=='X')
				wa[l]=1;
	for(int i=1;i<=m;i++)
		wa[i]+=wa[i-1];
	q=read();
	while(q--)
	{
		int x=read(),y=read();
		if(wa[y]-wa[x]==0)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}