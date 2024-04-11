#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
void solve()
{
	int n,x;
	cin>>n>>x;
	vector<int> p(n+1);
	p[1]=x;p[n]=1;
	vector<bool> vis(n+1);
	vis[x]=vis[1]=1;
	if(n%x!=0)
	{
		cout<<"-1\n";
		return;
	}
	for(int i=2;i<n;++i) p[i]=i;
	if(x!=n)
	{
		int y=n/x;
		for(int i=2;i<=y;++i)
		{
			while(y%i==0)
			{
				p[x]=x*i;
				x=x*i;
				y/=i;
			}
		}
	}
	
	for(int i=1;i<=n;++i) cout<<p[i]<<' ';
	cout<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}