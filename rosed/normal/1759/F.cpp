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
	int n,p;
	cin>>n>>p;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	int l=0,r=2*p;
	auto check=[&](int x) -> bool
	{
		typedef array<int,2> pr;
		vector<pr> tmp;
		for(int i=1;i<=n;++i) tmp.emplace_back(pr{a[i],a[i]});
		if(a[n]+x<p) tmp.emplace_back(pr{a[n],a[n]+x});
		else
		{
			bool flag=1;
			int y=x-(p-a[n]);
			y=min(y,p-1);
			tmp.emplace_back(pr{0,y});
			for(int i=n-1;i>=1;--i)
			{
				if(a[i]+1<p)
				{
					tmp.emplace_back(pr{a[i]+1,a[i]+1});flag=0;break;
				}
				else
				{
					tmp.emplace_back(pr{0,0});
				}
			}
			if(flag) tmp.emplace_back(pr{1,1});
		}
		int nxt=1;
		for(int i=n;i>=1;--i)
		{
			if(x<nxt)
			{

			}
			if(a[i]+x<p) tmp.emplace_back(pr{a[i],a[i]+x});
			else
			{
				if(i==1) tmp.emplace_back(pr{1,1});
				tmp.emplace_back(pr{a[i],p-1}); 
				int y=x-(p-1-a[i])-1;
				y=min(y,p-1);
				tmp.emplace_back(pr{0,y});
			}
			x/=p;
		}
		sort(tmp.begin(),tmp.end());
		int pre=-1;
		for(auto [x,y]:tmp)
		{
			if(x>pre+1) return 0;
			pre=max(pre,y);
		}
		return pre==p-1;
	};
	while(l<=r)
	{
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<r+1<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}