#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int t,n;
string s,ss;
void solve()
{
	n=read();
	cin>>s;
	ss="";
	int c=0,tot=0,cnt=0,ok=0;
	for(int i=0;i<s.size();i++)
	{
		if(i==n-1)
			break;
		if(s[i]==')'&&s[i+1]=='(')
		{
			int l=i+1;
			for(;l<n;l++)
				if(s[l]==')')
					break;
			if(l==n)
			{
				cout<<c<<" "<<n-tot<<'\n';
				return ;
			}
			c++;
			tot+=l-i+1;
			i=l;
		}
		else
		{
			c++;
			tot+=2;
			i++;
		}
	}
	cout<<c<<" "<<n-tot<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}