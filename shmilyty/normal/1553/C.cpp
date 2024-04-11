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
int t;
string s;
void solve()
{
	cin>>s;
	string ss=s;
	int ans=10;
	for(int i=0;i<10;i++)
		if(s[i]=='?')
			s[i]=(i&1?'0':'1');
	int cnt=0;
	for(int i=0;i<10;i++)
	{
		cnt+=((i%2==0)?s[i]-'0':'0'-s[i]);
		if(cnt>(10-i)/2)
		{
			ans=i+1;
			break;
		}
	}
	for(int i=0;i<10;i++)
		if(ss[i]=='?')
			ss[i]=(i&1?'1':'0');
	cnt=0;
	for(int i=0;i<10;i++)
	{
		cnt-=((i%2==0)?ss[i]-'0':'0'-ss[i]);
		if(cnt>(9-i)/2)
		{
			cout<<min(ans,i+1)<<endl;
			return ;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}