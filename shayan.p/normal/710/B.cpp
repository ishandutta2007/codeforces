#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=3e5+10,inf=1e18;
ll sum[maxn],a[maxn];
int main(){
	ll n;cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ll ans=inf,ans_ind;
	for(ll i=1;i<=n;i++){
		ll num=sum[n]-sum[i]-((n-i)*a[i])+(i*a[i])-sum[i];
		if(ans>num){
			ans=num;
			ans_ind=a[i];
		}
	}
	cout<<ans_ind;
}