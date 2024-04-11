#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
ll n,d,m,sa[N],sb[N];
ll ans;
vector<int>a;
vector<int>b;
int main()
{
	scanf("%lld %lld %lld",&n,&d,&m);
	for(int i=1;i<=n;++i)
	{
		ll x;
		scanf("%lld",&x);
		if(x<=m) 
			a.push_back(x);
		else 
			b.push_back(x);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int siza=a.size(),sizb=b.size();
	for(int i=1;i<=siza;++i) 
		sa[i]=a[i-1]+sa[i-1];
	for(int i=1;i<=sizb;++i) 
		sb[i]=b[i-1]+sb[i-1];
	ll ans=0;
	for(int i=0;i<=siza;++i)
	{
		int can=(n-i-1)/(d+1)+1;
		ans=max(ans,sa[siza]-sa[siza-i]+sb[sizb]-sb[max(0,sizb-can)]);
	}
	cout<<ans;
	return 0;
}