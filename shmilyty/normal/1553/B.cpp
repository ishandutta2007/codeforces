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
int T;
string s,t;
void solve()
{
	cin>>s>>t;
	for(int i=0;i<s.size();i++)
	{
		if(i+t.size()>=2*s.size())
		{
			puts("NO");
			return ;
		}
		bool flag=1;
		for(int l=0;l<=t.size();l++)
		{
			if(i+l>(int)s.size())
				break;
			if(t.substr(0,l)==s.substr(i,l))
			{
				if(i+l-((int)t.size()-l)-1<0)
					continue;
				string tt=t.substr(l,(int)t.size()-l);
				reverse(tt.begin(),tt.end());
				if(tt==s.substr(i+l-((int)t.size()-l)-1,((int)t.size()-l)))
				{
					puts("YES");
					return ;
				}
			}
			else
				break;
		}
	}
	puts("NO");
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}