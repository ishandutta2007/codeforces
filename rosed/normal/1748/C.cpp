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
	int n;
	cin>>n;
	vector<int> a(n+1);
	int maxn=0,sum=0,ans=0;
	bool flag=0;
	map<int,int> q;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			if(flag) ans+=maxn;
			else ans+=q[0];
			flag=1;
			maxn=0;
			q.clear();
		}
		sum+=a[i];
		maxn=max(maxn,++q[sum]);
	}
	if(flag) ans+=maxn;
	else ans+=q[0];
	cout<<ans<<'\n';

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}