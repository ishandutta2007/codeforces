#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=2e3+10,Big=5e9;
ll a[maxn],b[maxn],n,k,p;
bool check(ll num){
	ll j=0;
	for(ll i=0;i<n;i++){
		while(abs(a[i]-b[j])+abs(p-b[j])>num&&j<k){
			j++;
		}
		if(j==k)return 0;
		j++;
	}
	return 1;
}
int main(){
	cin>>n>>k>>p;
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<k;i++)cin>>b[i];
	sort(a,a+n);
	sort(b,b+k);
	ll l=0,r=Big,ans;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
}