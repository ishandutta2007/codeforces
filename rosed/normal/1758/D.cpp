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
	if(n==2)
	{
		cout<<3<<' '<<1<<'\n';
		return;
	}
	vector<int> a(n+1);
	auto cal=[&](int l,int r) -> int
	{
		return (l+r)*(r-l+1)/2;
	};
	auto check=[&](int x) -> bool
	{
		int l=1,r=x*x;
		while(l<=r)
		{
			int tmp=mid;
			a[1]=tmp,a[n]=tmp+x;
			// cout<<a[1]<<' '<<a[n]<<"!!"<<endl;
			int tl=a[1]+a[n]+cal(a[1]+1,a[1]+n-2);
			int tr=a[1]+a[n]+cal(a[n]-(n-2),a[n]-1);
			// cout<<tl<<' '<<tr<<"!!!!!!"<<endl;
			if(x*x<tl) r=mid-1;
			else if(x*x>tr) l=mid+1;
			else
			{
				// cout<<tl<<' '<<tr<<' '<<"??"<<endl;
				int tot=x*x-a[1]-a[n];
				for(int i=2;i<n;++i)
				{
					a[i]=a[1]+i-1;
					tot-=a[i];
				}
				int yy=tot/(n-2);
				tot-=yy*(n-2);
				for(int i=2;i<n;++i)
				{
					a[i]+=yy;
				}
				for(int i=n-1;i>1&&tot>0;--i)
				{
					++a[i];
					--tot;
				}
				return 1;
			}
		}
		return 0;
	};
	for(int x=n-1;;++x)
	{
		if(check(x))
		{
			for(int i=1;i<=n;++i)
			{
				cout<<a[i]<<" \n"[i==n];
			}
			return;
		}
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