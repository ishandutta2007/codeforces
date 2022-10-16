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
int t,n,m,cnt;
array<int,2> a[1000001];
multiset<int> s[2];
string ss;
bool cmp(array<int,2> x,array<int,2> y)
{
	if(x[0]-x[1]!=y[0]-y[1])
		return x[0]-x[1]<y[0]-y[1];
	if(x[0]+x[1]!=y[0]+y[1])
		return x[0]+x[1]<y[0]+y[1];
	return x[0]<y[0];
}
void solve()
{
	n=read();
	m=read();
	s[0].clear();
	s[1].clear();
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>ss;
		for(int l=0;l<m;l++)
			if(ss[l]=='1')
				a[++cnt]={i,l+1};
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int k=(a[i][0]+a[i][1])&1;
		multiset<int>::iterator l=s[k].lower_bound(-(a[i][0]+a[i][1]));
		if(l!=s[k].end())
			s[k].erase(l);
		s[k].insert(-(a[i][0]+a[i][1]));
	}
	cout<<s[0].size()+s[1].size()<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}