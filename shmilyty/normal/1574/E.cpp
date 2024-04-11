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
int n,m,k,badr,badc,er,ec,row[1000001][2],col[1000001][2],ok[2],mi[1000001];
map<pair<int,int>,int> mp;
const int mod=998244353;
void update(int x,int y,int v)
{
	if(row[x][0]&&row[x][1])
		badr+=v;
	if(col[y][0]&&col[y][1])
		badc+=v;
	if(row[x][0]+row[x][1]==0)
		er+=v;
	if(col[y][0]+col[y][1]==0)
		ec+=v; 
}
void add(int x,int y,int v)
{
	update(x,y,-1);
	row[x][(y+mp[{x,y}])%2]+=v;
	col[y][(x+mp[{x,y}])%2]+=v;
	ok[(x+y+mp[{x,y}])%2]+=v;
	update(x,y,1);
}
signed main()
{
	er=n=read();
	ec=m=read();
	k=read();
	mi[0]=1;
	for(int i=1;i<=max(n,m);i++)
		mi[i]=(mi[i-1]*2)%mod;
	while(k--)
	{
		int x=read(),y=read(),t=read()+1;
		if(mp[{x,y}])
			add(x,y,-1);
		mp[{x,y}]=t;
		if(t)
			add(x,y,1);
		int ans=(badr?0:mi[er])+(badc?0:mi[ec]);
		if(!ok[0])
			ans--;
		if(!ok[1])
			ans--;
		cout<<(ans+mod)%mod<<endl; 
	}
	return 0;
}