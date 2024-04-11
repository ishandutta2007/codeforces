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
int t,num[26];
string s;
void solve()
{
	cin>>s;
	for(int i=0;i<26;i++)
		num[i]=0;
	for(int i=0;i<s.size();i++)
		num[s[i]-'a']++;	
	int ans=0,tot=0;
	for(int i=0;i<26;i++)
	{
		if(num[i]==1)
			tot++;
		if(num[i]>1)
			ans++;
	}
	cout<<ans+tot/2<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}