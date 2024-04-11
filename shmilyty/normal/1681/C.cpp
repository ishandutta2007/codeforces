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
int t,n,id[101];
array<int,3> a[101],b[101];
std::vector<array<int,2>> v;
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i][0]=b[i][0]=read();
	for(int i=1;i<=n;i++)
		a[i][1]=b[i][1]=read();
	for(int i=1;i<=n;i++)
		a[i][2]=b[i][2]=i;
	sort(b+1,b+1+n);
	for(int i=1;i<n;i++)
		if(b[i][1]>b[i+1][1])
		{
			puts("-1");
			return ;
		}
	v.clear();
	for(int i=1;i<=n;i++)
		id[i]=b[i][2];
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			if(a[l][2]==id[i])
			{
				v.push_back({i,l});
				swap(a[l],a[i]);
			}
	cout<<v.size()<<'\n';
	for(auto i:v)
		cout<<i[0]<<" "<<i[1]<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}