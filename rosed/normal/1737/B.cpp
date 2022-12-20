#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int inf=1e15;
void solve()
{
	int l,r;
	cin>>l>>r;
	auto solve=[&](int x) -> int
	{
		int l=0,r=1e9;
		while(l<=r)
		{
			if(mid*mid<=x) l=mid+1;
			else r=mid-1;
		}
		int q=l-1;
		int ans=3*(q-1);
		if(q*q<=x) ++ans;
		if(q*(q+1)<=x) ++ans;
		if(q*(q+2)<=x) ++ans;
		return ans;
	};
	cout<<solve(r)-solve(l-1)<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;cin>>T;
	while(T--) solve();
	return 0;
}
/*
2*2
2*3
2*4
3*3
3*4
3*5
4*4
4*5
4*6
5*5
5*6
5*7
6*6
6*7
6*8
*/