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
int n,q,a[500001],ans[500001];
array<int,2> res,t[1000001];
map<int,int> mp;
vector<array<int,2>> v[500001]; 
array<int,2> query(int x,int y)
{
	array<int,2> ret={INF,0};
	for(x+=n,y+=n;x<y;x>>=1,y>>=1)
	{
		if(x&1)
		{
			if(ret[0]>t[x][0])
				ret=t[x];
			x++;
		}
		if(y&1)
		{
			y--;
			if(ret[0]>t[y][0])
				ret=t[y];
		}
	}
	return ret;
}
void modify(int x,array<int,2> y)
{
	x+=n;
	t[x]=y;
	for(;x>1;x>>=1)
		if(t[x][0]<t[x^1][0])
			t[x>>1]=t[x];
		else
			t[x>>1]=t[x^1];
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<2*n;i++)
		t[i][0]=100000000;
	q=read();
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		v[y].push_back({x,i});
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[a[i]])
		{
			modify(mp[a[i]]-1,{100000000,0});
			modify(i-1,{mp[a[i]],a[i]});
		}
		else
			modify(i-1,{0,a[i]});
		mp[a[i]]=i;
		res=query(i-1,i);
		res=t[i+n-1];
		for(auto l:v[i])
		{
			res=query(l[0]-1,i);
			if(res[0]>=l[0])
				ans[l[1]]=0;
			else
				ans[l[1]]=res[1];
		}
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<'\n';
	return 0;
}