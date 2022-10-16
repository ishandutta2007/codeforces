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
int t,n,a[10001],vis[10001];
void solve()
{
	cin>>n;
	fill(vis+1,vis+1+n,0);
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			cout<<"? "<<i<<endl;
			int x;
			cin>>x;
			int y=x;
			while(1)
			{
				cout<<"? "<<i<<endl;
				cin>>a[x];
				vis[x]=1;
				x=a[x];
				if(x==y)
					break;
			 } 
		}
	cout<<"!";
	for(int i=1;i<=n;i++)
		cout<<" "<<a[i];
	cout<<endl;
}
signed main()
{
	cin>>t;
	while(t--)
		solve();
	return 0;
}