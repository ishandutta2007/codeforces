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
int n,N=4e5,cnt,t[800001];
array<int,3> a[200001];
map<int,int> mp;
#define lowbit(x) (x&(-x))
void add(int x)
{
	for(;x<=N;x+=lowbit(x))
		t[x]++;
}
int query(int x)
{
	int res=0;
	for(;x;x^=lowbit(x))
		res+=t[x];
	return res;
}
bool cmp(array<int,3> x,array<int,3> y)
{
	if(x[0]!=y[0])
		return x[0]<y[0];
	if(x[1]!=y[1])
		return x[1]>y[1];
	return x[2]<y[2];
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		mp[x];
		mp[y];
		a[i]={x,y,i};
	}
	sort(a+1,a+1+n);
	for(int i=2;i<n;i++)
		if(a[i-1][1]+1>=a[i+1][0]&&a[i][0]<=a[i-1][1]&&a[i][0]>=a[i-1][0]&&a[i][1]>=a[i+1][0]&&a[i][1]<=a[i+1][1])
		{
			cout<<a[i][2];
			return 0;
		}
	for(auto &i:mp)
		i.second=++cnt;
	for(int i=1;i<=n;i++)
		a[i]={mp[a[i][0]],mp[a[i][1]],a[i][2]};
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<" "<<a[i][0]<<" "<<a[i][1]<<" "<<query(a[i][1])<<endl;
		if(query(a[i][1]-1)!=i-1)
		{
			cout<<a[i][2];
			return 0;
		}
		add(a[i][1]);
	}
	puts("-1");
	return 0;
}