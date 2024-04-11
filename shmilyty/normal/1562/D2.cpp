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
vector<int> v[600001];
int work(int x,int y)
{
	int tot=f[y]-f[x-1];
	if(tot>0)
		tot=(tot+1)/2;
	else
		tot=(tot-1)/2;
	tot+=f[x-1]+n;
	/*
	int tot=f[x-1]+f[y];
	if(tot>0)
		tot=(tot+1)/2;
	else
		tot=(tot-1)/2;
	tot+=n;
	*/
	return *lower_bound(v[tot].begin(),v[tot].end(),x);
}
void solve()
{
	n=read();
	q=read();
	cin>>s; 
	for(int i=0;i<=2*n;i++)
		v[i].clear();
	for(int i=0;i<s.size();i++)
		f[i+1]=f[i]+(s[i]=='+'?1:-1)*((i&1)?-1:1);
	for(int i=1;i<=n;i++)
		v[f[i]+n].push_back(i);
	while(q--)
	{
		int x=read(),y=read();
		int v=f[y]-f[x-1];
		if((y-x+1)&1)
		{
			puts("1");
			cout<<work(x,y)<<endl;
			continue;
		}
		if(!v)
		{
			puts("0");
			continue;
		}
		puts("2");
		cout<<x<<" "<<work(x+1,y)<<endl;
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}