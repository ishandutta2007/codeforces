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
int n,m,q,mx[1600001],mn[1600001],ok[1600001];
set<int> s[400001];
void modify(int x,int l,int r,int k)
{
	if(l==r)
	{
		mx[x]=-INF;
		mn[x]=INF;
		if(!s[k].empty())
		{
			if(k&1)
				mn[x]=*s[k].begin();
			else
				mx[x]=*s[k].rbegin();
		}
		return ;
	}
	int mid=(l+r)>>1;
	if(k<=mid)
		modify(x<<1,l,mid,k);
	else
		modify(x<<1|1,mid+1,r,k);
	mn[x]=min(mn[x<<1],mn[x<<1|1]);
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
	ok[x]=ok[x<<1]|ok[x<<1|1];
	if(mn[x<<1]<mx[x<<1|1])
		ok[x]=1;
}
signed main()
{
	n=read();
	m=read();
	q=read();
	fill(mn+1,mn+1+8*n,INF);
	fill(mx+1,mx+1+8*n,-INF);
	while(q--)
	{
		int x=read(),y=read();
		if(s[x].count(y))
			s[x].erase(y);
		else
			s[x].insert(y);
		modify(1,1,n*2,x);
		if(ok[1])
			puts("No");
		else
			puts("Yes");
	}
	return 0;
}