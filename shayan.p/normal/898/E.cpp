#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=2e5+10;
ll zero,com;
vector<ll>v;
int main(){
	ll n;cin>>n;
	for(ll i=0;i<n;i++){
		ll num;cin>>num;
		ll x=sqrt(num);
		if((x*x)!=num){
			v.PB(min(num-(x*x),((x+1)*(x+1))-num));
		}
		else{
			if(num==0)zero++;
			else com++;
		}
	}
	if(com+zero>(n/2)){
		ll should=n/2;
		if(zero<=(n/2)){
			cout<<com+zero-(n/2);
			return 0;
		}
		else{
			cout<<com+2*(zero-(n/2));
			return 0;
		}
	}
	else{
		ll ans=0;
		sort(v.begin(),v.end());
		for(ll i=0;i<(n/2)-zero-com;i++){
			ans+=v[i];
		}
		cout<<ans;
		return 0;
	}
}