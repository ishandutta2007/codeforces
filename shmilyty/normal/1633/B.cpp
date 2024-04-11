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
int t,num[2];
string s;
void solve()
{
	cin>>s;
	int n=s.size();
	num[0]=num[1]=0;
	for(int i=0;i<n;i++)
		num[s[i]-'0']++;
	if(num[0]!=num[1])
	{
		cout<<min(num[0],num[1])<<'\n';
		return ;
	}
	cout<<num[0]-1<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}