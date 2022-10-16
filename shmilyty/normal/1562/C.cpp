#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int n,t;
string s;
void solve()
{
	n=read();
	cin>>s;
	int flag=1;
	for(int i=1;i<=s.size();i++)
		if(s[i-1]=='0')
		{
			flag=0;
			if(i<=n/2)
				cout<<i<<" "<<n<<" "<<i+1<<" "<<n<<endl;
			else
				cout<<1<<" "<<i<<" "<<1<<" "<<i-1<<endl;
			return ;
		}
	cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}