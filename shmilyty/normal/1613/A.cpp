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
int t,n1,n2,p1,p2;
string s1,s2;
void solve()
{
	n1=read();
	p1=read();
	n2=read();
	p2=read();
	s1=to_string(n1);
	s2=to_string(n2);
	if(s1.size()+p1>s2.size()+p2)
	{
		puts(">");
		return ;
	}
	if(s1.size()+p1<s2.size()+p2)
	{
		puts("<");
		return ;
	}
	while(p1>p2)
	{
		p1--;
		n1*=10;
	}
	while(p1<p2)
	{
		p2--;
		n2*=10;
	}
	if(n1>n2)
		puts(">");
	elif(n1==n2)
		puts("=");
	else
		puts("<");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}