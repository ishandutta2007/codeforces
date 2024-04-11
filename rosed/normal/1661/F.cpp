#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=1e6+10,mod=1e9+7,inf=INT_MAX;
	int n,m;
	int a[N];
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		cin>>m;
		auto getval = [&](int x,int y)
		{
			int v=x/(y+1);
			int c=x%(y+1);
			return v*v*(y+1-c)+(v+1)*(v+1)*c;
		};
		auto check = [&] (auto x)
		{
			int cnt=0,val=0;
			//cout<<x<<endl;
			for(int i=0;i<n;++i)
			{
				int l=1,r=a[i+1]-a[i]-1;
				while(l<=r)
				{
					if(getval(a[i+1]-a[i],mid-1)-getval(a[i+1]-a[i],mid)>=x) l=mid+1;
					else r=mid-1;
				}
				//cout<<l-1<<' ';
				cnt+=l-1,val+=getval(a[i+1]-a[i],l-1);
			}
			//cout<<endl;
			return pair(cnt,val);
		};
		int l=0,r=1e18;
		while(l<=r)
		{
			//cout<<l<<' '<<r<<' '<<mid<<"!!"<<endl;
			auto [cnt,val]=check(mid);
			if(val<=m) l=mid+1;
			else r=mid-1;
		}
		auto [cnt,val]=check(l);
		//cout<<cnt<<' '<<val<<"!!"<<endl;	
		cout<<cnt+(val-m+l-2)/(l-1)<<'\n';
	}
}
signed main()
{
	red::main();
	return 0;
}
/*


*/