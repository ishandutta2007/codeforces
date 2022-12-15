// LUOGU_RID: 96107502
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int mod=1e9+7;
const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)
	{
		a[i]=1<<i;
	}
	vector<int> qwq;
	typedef array<int,2> pr;
	vector<pr> tmp;
	for(int i=0;i<n/2;++i) tmp.emplace_back(pr{i,n-1-i});
	for(auto [x,y]:tmp)
	{
		for(int i=y-1;i>=x;--i)
		{
			qwq.emplace_back(i);
		}
		for(int i=x+1;i<y;++i)
		{
			qwq.emplace_back(i);
		}
	}
	for(int i=0;i<n/2-(n%2==0);++i)
	{
		qwq.emplace_back(i);
	}

	reverse(tmp.begin(),tmp.end());
	for(auto [y,x]:tmp)
	{
		y+=n;
		for(int i=y-1;i>=x;--i)
		{
			qwq.emplace_back((i%n+n)%n);
		}
		for(int i=x+1;i<y;++i)
		{
			qwq.emplace_back((i%n+n)%n);
		}
	}
	for(int i=n/2+(n&1);i<n-1;++i)
	{
		qwq.emplace_back(i);
	}
	reverse(tmp.begin(),tmp.end());
	for(auto [x,y]:tmp)
	{
		for(int i=y-1;i>=x;--i)
		{
			qwq.emplace_back(i);
		}
		for(int i=x+1;i<y;++i)
		{
			qwq.emplace_back(i);
		}
	}
	
	for(int i=0;i<n/2-(n%2==0);++i)
	{
		qwq.emplace_back(i);
	}
	
	cout<<qwq.size()<<'\n';
	for(int x:qwq)
	{
		a[x]^=a[(x+1)%n];
		cout<<x<<' ';
	}
	// cout<<'\n';
	// for(int i=0;i<n;++i) cout<<a[i]<<' ';
	// 	cout<<'\n';
}
signed main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
}