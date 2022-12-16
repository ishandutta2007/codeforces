#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x,y;
const ll maxa=1e15+10;
ll binary(ll targ,ll l=0,ll r=maxa){
	ll ans;
	while(l<=r){
		ll mid=(l+r)/2;
		if((mid/x)+(mid/y)>=targ){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
void solve(ll a){
	ll t=binary(a);
	if(t%x==0&&t%y==0)cout<<"Both";
	else if(t%y==0)cout<<"Vanya";
	else if(t%x==0)cout<<"Vova";
	cout<<endl;
}
int main(){
	cin>>n>>x>>y;
	for(ll i=0;i<n;i++){
		ll a;cin>>a;
		solve(a);
	}
}