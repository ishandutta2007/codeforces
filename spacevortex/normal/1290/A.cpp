#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5050;
ll n,m,K,ans;
ll a[N];
void Solve()
{
	ll i,j,val,now;
	cin>>n>>m>>K;
	K=min(K,m-1);
	ans=0;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=0;i<=K;i++)
	{
		now=1e9+50;
		for(j=0;j<=m-1-K;j++)
		{
			val=max(a[i+j+1],a[n-(m-1-i-j)]);
			now=min(now,val);
		}
		ans=max(ans,now);
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	ll T;
	cin>>T;
	while(T--)
	{
		Solve();
	}
	return 0;
}