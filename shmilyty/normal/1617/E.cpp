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
int n,res;
array<int,2> ans;
map<int,array<int,2>> mp;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		mp[read()]={0,i};
	int x=INF;
	while(1)
	{
		auto it=--mp.lower_bound(x);
		x=it->first;
		if(!x)
			break;
		int fa;
		for(int i=0;i<31;i++)
			if((1<<i)>=x)
			{
				fa=(1<<i)-x;
				break; 
			}
		if(mp.find(fa)==mp.end())
			mp[fa]={-INF,0};
		if(mp[fa][0]+it->second[0]+1>res)
		{
			res=mp[fa][0]+it->second[0]+1;
			ans={mp[fa][1],it->second[1]};
		}
		mp[fa]=max(mp[fa],{it->second[0]+1,it->second[1]});
	}
	cout<<ans[0]<<" "<<ans[1]<<" "<<res;
	return 0;
}