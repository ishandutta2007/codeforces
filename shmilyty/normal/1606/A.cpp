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
int T,a,b;
string s,t[4]; 
int work(string s)
{
	int cnt=0;
	for(int i=1;i<s.size();i++)
		if(s[i]!=s[i-1])
		{
			if(s[i-1]=='a')
				cnt++;
			else
				cnt--;
		}
	return cnt;
}
void solve()
{
	cin>>s;
	for(int i=0;i<4;i++)
		t[i]=s;
	t[1][0]='a'+'b'-t[1][0];
	t[3][0]='a'+'b'-t[3][0];
	t[2][s.size()-1]='a'+'b'-t[2][s.size()-1];
	t[3][s.size()-1]='a'+'b'-t[3][s.size()-1];
	int res=INF;
	string ans;
	for(int i=0;i<4;i++)
	{
		if(work(t[i])==0)
		{
			int val=(i%2)+(i/2);
			if(val<res)
			{
				res=val;
				ans=t[i];
			}
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}