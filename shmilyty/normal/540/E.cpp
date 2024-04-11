#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
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
int n,c,ans,t[400001];
map<int,int> mp,cnt;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x)
{
	for(;x<=2*n;x+=lowbit(x))
		t[x]+=1;
}
int query(int x)
{
	int ans=0;
	for(;x;x-=lowbit(x))
		ans+=t[x];
	return ans;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if(!mp[x])
			mp[x]=x;
		if(!mp[y])
			mp[y]=y;
		swap(mp[x],mp[y]);
	}
	for(auto i:mp)
	{
		int x=i.first;
		cnt[x]=++c;
	}
	for(auto i:mp)
	{
		int x=i.first,y=i.second;
		ans+=abs(x-y-cnt[x]+cnt[y]);
		ans+=cnt[x]-query(cnt[y])-1;
		add(cnt[y]);
	}
	cout<<ans<<endl;
	return 0;
}