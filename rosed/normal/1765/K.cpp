#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
void solve()
{
	int n;
	cin>>n;
	int sum=0,minn=1e18;
	vector a(n+1,vector<int>(n+1));
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>a[i][j];
			sum+=a[i][j];
			if(i+j==1+n) minn=min(minn,a[i][j]);
		}
	}
	cout<<sum-minn<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
}