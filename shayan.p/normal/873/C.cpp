#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define S second
#define F first
#define PB push_back
#define MP make_pair
using namespace std;
int main()
{
	ll n,m,k;cin>>n>>m>>k;ll a[200][200],sum[1000];ll ans=0,change=0;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			cin>>a[j][i];
			for(ll i=1;i<=m;i++)
			{
				sum[n+1]=0;
				for(ll j=n;j>0;j--) sum[j]=sum[j+1]-a[i][min(j+k,n+1)]+a[i][j];
				ll Max=n+1;
				for(ll j=1;j<=n;j++) if(a[i][j]==1) if(sum[j]>sum[Max]) Max=j;// agar chand sum max bozorgtar mosavi bashan
				ans+=sum[Max];
				for(ll j=1;j<Max;j++) change+=a[i][j];
			}
			cout<<ans<<" "<<change;
}