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
int T,n,m,ans,a[1000001],b[1000001],t[2000001];
array<int,2> c[1000001];
priority_queue<int> q;
void modify(int x)
{
	if(q.empty())
		q.push(x);
	elif(q.top()<x)
		q.push(x);
	else
	{
		ans+=q.top()-x;
		q.push(x);
		q.push(x);
		q.pop();
	}
}
int lowbit(int x)
{
	return x&-x;
}
void add(int x)
{
	for(;x<=n;x+=lowbit(x))
		t[x]++;
}
int query(int x)
{
	int res=0;
	for(;x;x-=lowbit(x))
		res+=t[x];
	return res;
}
void solve()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		c[i]={a[i],i};
	}
	for(int i=1;i<=m;i++)
		b[i]=read();
	sort(c+1,c+1+n);
	sort(b+1,b+1+m);
	while(!q.empty())
		q.pop();
	ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=lower_bound(b+1,b+1+m,a[i])-b-1,r=upper_bound(b+1,b+1+m,a[i])-b-1;
//		cout<<l<<" "<<r<<endl;
		modify(r);
		modify(l);
		ans-=(r-l);
	}
//	cout<<ans<<endl;
	ans/=2;
	fill(t+1,t+1+2*n,0);
	for(int i=1;i<=n;i++)
	{
		ans+=i-1-query(c[i][1]);
		add(c[i][1]);
	}
	cout<<ans<<endl;
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}