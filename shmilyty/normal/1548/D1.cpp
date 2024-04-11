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
int n,ans,a[4];
array<int,3> t[16]={
	{0,0,0},
	{0,0,1},
	{0,0,2},
	{0,0,3},
	{0,1,1},
	{0,2,2},
	{0,3,3},
	{1,1,1},
	{1,1,2},
	{1,1,3},
	{1,2,2},
	{1,3,3},
	{2,2,2},
	{2,2,3},
	{2,3,3},
	{3,3,3}
	};
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read()/2,y=read()/2;
		a[x%2*2+y%2]++;
	} 
	for(int i=0;i<=15;i++)
	{
		if(t[i][0]==t[i][1]&&t[i][1]==t[i][2])
		{
			ans+=a[t[i][0]]*(a[t[i][0]]-1)*(a[t[i][0]]-2)/6;
			continue;
		}
		if(t[i][0]==t[i][1])
		{
			ans+=a[t[i][0]]*(a[t[i][0]]-1)/2*a[t[i][2]];
			continue;
		}
		if(t[i][1]==t[i][2])
		{
			ans+=a[t[i][1]]*(a[t[i][1]]-1)/2*a[t[i][0]];
			continue;
		}
		ans+=a[t[i][0]]*a[t[i][1]]*a[t[i][2]];
	}
	cout<<ans<<endl;
	return 0;
}