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
int t,n,t1,t2,ans1,ans2;
string s1,s2;
void solve()
{
	n=read();
	cin>>s1>>s2;
	t1=t2=ans1=ans2=0;
	for(int i=0;i<n;i++)
		if(s1[i]!=s2[i])
		{
			ans1++;
			if(s1[i]=='0')
				t1++;
			else
				t2++;
		}
	if(ans1&1||t1!=t2)
		ans1=n+1;
	t1=t2=0;
	for(int i=0;i<n;i++)
		if(s1[i]==s2[i])
		{
			ans2++;
			if(s1[i]=='0')
				t1++;
			else
				t2++;
		}
	if(ans2%2==0||t1+1!=t2)
		ans2=n+1;
	if(min(ans1,ans2)==n+1)
		puts("-1");
	else
	cout<<min(ans1,ans2)<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}