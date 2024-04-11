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
int t,n,num[10];
string s;
void solve()
{
	n=read();
	cin>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='1'||(s[i]%2==0&&s[i]!='2')||s[i]=='9')
		{
			puts("1");
			cout<<s[i]<<endl;
			return ;
		}
	for(int i=1;i<n;i++)
		if(s[i]=='5'||s[i]=='2')
		{
			puts("2");
			cout<<s[i-1]<<s[i]<<endl;
			return ;
		}
	memset(num,0,sizeof(num));
	for(int i=0;i<n;i++)
		if(num[s[i]-'0'])
		{
			puts("2");
			cout<<s[i]<<s[i]<<endl;
			return ;
		}
		else
			num[s[i]-'0']=1;
	for(int i=1;i<n;i++)
		if(s[i]=='7'&&(s[0]=='2'||s[0]=='5'))
		{
			puts("2");
			cout<<s[0]<<s[i]<<endl;
			return ;
		}
	puts("Impossible");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}