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
int t,n,q,f[300001];
string s;
void solve()
{
	n=read();
	q=read();
	cin>>s; 
	for(int i=0;i<s.size();i++)
		f[i+1]=f[i]+(s[i]=='+'?1:-1)*((i&1)?-1:1);
	while(q--)
	{
		int x=read(),y=read();
		int v=f[y]-f[x-1];
		if((y-x+1)&1)
		{
			puts("1");
			continue;
		}
		cout<<(v?2:0)<<endl;	
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}