#include<bits/stdc++.h>
#define  pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define vll vector<ll>
#define vvll vector<vector<ll> >
typedef long long ll;
using namespace std;
ll sum[6000];
ll f(ll a,ll b)
{
	return sum[b]-sum[a];
}
int main()
{
	ll n,i,j,pic1,pic2;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	sum[0]=0;
	ll Max=sum[n];
	ll ans1=0,ans2=0,ans3=n;
	for(i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i-1];
	for(i=0;i<=n;i++)
	{
		pic1=0;
		for(j=0;j<=i;j++)
		{
			if(f(0,j)>f(0,pic1))
			{
			pic1=j;
			}
		}
		pic2=i;
		for(j=i;j<=n;j++)
		{
			if(f(i,j)>f(i,pic2))
			pic2=j;
		}
		ll m=f(0,pic1)-f(pic1,i)+f(i,pic2)-f(pic2,n);
		if(Max<m)
		{
			ans1=pic1;
			ans2=i;
			ans3=pic2;
			Max=m;
		}
	}
	cout<<ans1<<" "<<ans2<<" "<<ans3;
}