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
int t,n,a,b;
string s;
void solve()
{
	n=read();
	a=read();
	b=read();
	cin>>s;
	if(b>=0)
	{
		cout<<n*a+n*b<<endl; 
		return ;
	}
	int ans=1;
	for(int i=1;i<s.size();i++)
		if(s[i]!=s[i-1])
			ans++;
	cout<<n*a+(ans/2+1)*b<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}