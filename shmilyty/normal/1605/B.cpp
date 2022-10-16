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
int t,n,a[2];
string s;
vector<int> ans;
void solve()
{
	n=read();
	cin>>s;
	a[0]=a[1]=0;
	for(int i=0;i<n;i++)
		a[s[i]-'0']++;
	ans.clear();
	for(int i=0;i<a[0];i++)
		if(s[i]=='1')
			ans.push_back(i+1);
	for(int i=a[0];i<n;i++)
		if(s[i]=='0')
			ans.push_back(i+1);
	if(ans.empty())
		puts("0");
	else
	{
		puts("1");
		cout<<ans.size();
		for(int i:ans)
			cout<<" "<<i;
		cout<<endl;
	 } 
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}