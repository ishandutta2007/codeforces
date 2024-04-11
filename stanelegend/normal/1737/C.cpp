#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

int t,n,x,y;
pii r1,r2,r3;

int main()
{
	cin>>t;
	rep(tn,t)
	{
		cin>>n>>r1.fi>>r1.se>>r2.fi>>r2.se>>r3.fi>>r3.se;
		cin>>x>>y;

		int xx=r1.fi^r2.fi^r3.fi,yy=r1.se^r2.se^r3.se;
		pii bad=mpr(1,1);
		if((r1==bad||r2==bad||r3==bad)&&mpr(xx,yy)==mpr(2,2))
		{
			if(x==1||y==1) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		bad=mpr(1,n);
		if((r1==bad||r2==bad||r3==bad)&&mpr(xx,yy)==mpr(2,n-1))
		{
			if(x==1||y==n) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		bad=mpr(n,1);
		if((r1==bad||r2==bad||r3==bad)&&mpr(xx,yy)==mpr(n-1,2))
		{
			if(x==n||y==1) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		bad=mpr(n,n);
		if((r1==bad||r2==bad||r3==bad)&&mpr(xx,yy)==mpr(n-1,n-1))
		{
			if(x==n||y==n) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		if(x%2==xx%2&&y%2==yy%2) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}