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
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	int maxn=0;
	bool flag=1;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	int t=1,idx=1;
	while(t<=n||m>0)
	{
		// cout<<t<<' '<<idx<<' '<<m<<endl;
		if(t<=n&&a[t]<idx)
		{
			cout<<"NO\n";
			return;
		}
		if(t>n||a[t]>idx)
		{
			m-=idx;
		}
		else ++t;
		++idx;
		// cout<<t<<' '<<idx<<' '<<m<<endl;
	}
	if(m==0)
	{
		cout<<"YES\n";
		return;
	}
	else
	{
		cout<<"NO\n";return;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}