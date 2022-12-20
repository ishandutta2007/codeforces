#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=2010,inf=1e18;
ll dp[2010];
vector<ll>v;
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll Gcd[2010][2010];
int main()
{
	ll n;cin>>n;
	ll Min=inf;
	ll cnt=0;
	for(ll i=0;i<n;i++)
	{
		ll x;cin>>x;
		if(x==1)cnt++;
		Gcd[i][i]=x;
		for(ll j=0;j<i;j++)
		{
			Gcd[j][i]=gcd(Gcd[j][i-1],x);
			if(Gcd[j][i]==1)Min=min(Min,i-j);
		}
	}
	if(cnt>0){cout<<n-cnt;return 0;}
	if(Min==inf)cout<<-1;
	else cout<<Min+n-1;
}