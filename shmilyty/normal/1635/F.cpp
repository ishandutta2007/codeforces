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
int n,q,top,stk[300001],t[300001],ans[300001];
array<int,2> a[300001];
vector<array<int,2>>qu[300001],val[300001];
void add(int x,int y)
{
	val[x].push_back({y,abs(a[x][0]-a[y][0])*(a[x][1]+a[y][1])});
}
void modify(int x,int y)
{
	for(;x<=n;x+=lowbit(x))
		t[x]=min(t[x],y);
}
int query(int x)
{
	int res=INF;
	for(;x;x^=lowbit(x))
		res=min(res,t[x]);
	return res;
}
signed main()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),w=read();
		a[i]={x,w};
		while(top)
		{
			add(stk[top],i);
			if(a[stk[top]][1]<w)
				break;
			top--;
		}
		stk[++top]=i;
	}
	fill(t,t+1+n,INF);
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		qu[x].push_back({y,i});
	}
	for(int i=n;i;i--)
	{
		for(auto l:val[i])
			modify(l[0],l[1]);
		for(auto l:qu[i])
			ans[l[1]]=query(l[0]);
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<'\n';
	return 0;
}