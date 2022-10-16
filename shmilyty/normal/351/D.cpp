#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int n,a[100001],q,ans[100001],t[2][100001],lft[100001],lst[100001],P[100001];
vector<array<int,2>> v[100001]; 
void modify(int ty,int x,int val)
{
	for(;x;x^=lowbit(x))
		t[ty][x]+=val;
}
int query(int ty,int x)
{
	int res=0;
	for(;x<=n;x+=lowbit(x))
		res+=t[ty][x];
	return res;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		lft[i]=lst[a[i]];
		lst[a[i]]=i;
		if(i-lft[i]==lft[i]-lft[lft[i]])
			P[i]=P[lft[i]];
		else
			P[i]=lft[lft[i]];
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		v[y].push_back({x,i});
	}
	for(int i=1;i<=n;i++)
	{
		if(lft[i])
		{
			modify(0,lft[i],-1);
			modify(1,P[lft[i]],1);
			modify(1,lft[i],-1);
		}
		modify(0,i,1);
		modify(1,P[i],-1);
		modify(1,i,1);
		for(auto l:v[i])
			ans[l[1]]=(!query(1,l[0])+query(0,l[0]));
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<'\n';
	cout<<endl; 
	return 0;
}