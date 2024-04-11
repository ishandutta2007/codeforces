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
int t,n,m,tot,idx[200001],cnt[200001],mx[200001];
array<int,2> a[200002];
std::vector<array<int,3>> v;
multiset<int> s;
void solve()
{
	n=read();
	m=read();
	v.clear();
	for(int i=1;i<=n;i++)
		v.push_back({read(),read(),i});
	sort(ALL(v));
	fill(cnt,cnt+2+n,0);
	fill(mx,mx+2+n,0);
	for(int i=0;i<n;i++)
	{
		a[i+1]={v[i][0],v[i][1]};
		idx[v[i][2]]=i+1;
	}
	s.clear();
	tot=0;
	for(int i=1;i<=n;i++)
	{
		// cout<<a[i][0]<<" "<<a[i][1]<<endl;
		while(!s.empty()&&(*s.begin())<=a[i][0])
		{
			tot-=((*s.begin())-a[i-1][0]);
			s.erase(s.find(*s.begin()));
		}
		// cout<<tot<<endl;
		tot-=(a[i][0]-a[i-1][0])*(s.size());
		tot+=a[i][1];
		cnt[i]+=tot;
		s.insert(a[i][0]+a[i][1]);
	}
	// cout<<tot<<endl;
	s.clear();
	a[n+1]={INF,0};
	tot=0;
	for(int i=n;i;i--)
	{
		while(!s.empty()&&-(*s.begin())>=a[i][0])
		{
			tot-=((*s.begin())+a[i+1][0]);
			s.erase(s.find(*s.begin()));
		}
		// cout<<tot<<endl;
		tot-=(a[i+1][0]-a[i][0])*(s.size());
		s.insert(a[i][1]-a[i][0]);
		cnt[i]+=tot;
		tot+=a[i][1];
	}
	for(int i=1;i<=n;i++)
		cnt[i]=max(0ll,cnt[i]-m);
	int x=-INF;
	for(int i=1;i<=n;i++)
	{
		x+=a[i][0]-a[i-1][0];
		if(cnt[i])
			x=max(x,cnt[i]);
		mx[i]=max(mx[i],x);
	}
	x=-INF;
	for(int i=n;i;i--)
	{
		x+=a[i+1][0]-a[i][0];
		if(cnt[i])
			x=max(x,cnt[i]);
		mx[i]=max(mx[i],x);
	}
	for(int i=1;i<=n;i++)
		if(mx[idx[i]]<=a[idx[i]][1])
			cout<<1;
		else
			cout<<0;
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}