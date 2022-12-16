#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=1e6;
ll cube(ll num,ll l=1,ll r=maxn){
	while(l<=r){
		ll mid=(l+r)/2;
		ll val=mid*mid*mid;
		if(val==num)return mid;
		if(val>num)r=mid-1;
		if(val<num)l=mid+1;
	}
	return 0;
}
int main()
{
	ll n;cin>>n;
	for(ll i=0;i<n;i++){
		ll a,b;scanf("%lld%lld",&a,&b);
		ll ans=cube(a*b);
		bool no=0;
		if(ans==0)printf("NO\n");
		else if(a%ans==0&&b%ans==0)printf("YES\n");
		else printf("NO\n");
	}
}