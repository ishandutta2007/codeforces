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
string s;
int t;
void solve()
{
	cin>>s;
	int n=s.size();
	if(n&1)
	{
		puts("No");
		return ;
	}
	string ss=s.substr(0,n/2);
	if(ss+ss==s)
		puts("Yes");
	else
		puts("No");
}
signed main()
{
	t=read();
	while(t--)
		solve(); 
	return 0;
}