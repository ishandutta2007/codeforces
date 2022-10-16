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
int t,n,k,mx,sum;
vector<int> v1,v2;
void solve()
{
	n=read();
	k=read();
	v1.clear();
	v2.clear();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(x>0)
			v1.push_back(-x);
		else
			v2.push_back(x);
	}
	sort(ALL(v1));
	sort(ALL(v2));
	mx=sum=0;
	for(int i=0;i<v1.size();i++)
		if(i%k==0)
		{
			sum-=v1[i];
			mx=max(mx,-v1[i]);
		}
	for(int i=0;i<v2.size();i++)
		if(i%k==0)
		{
			sum-=v2[i];
			mx=max(mx,-v2[i]);
		}
	cout<<sum*2-mx<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}