#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	ll x,y,ans=0;
	cin>>x>>y;
	vector<ll> d;
	for(ll i=1;i*i<=x;i++)
		if(x%i==0){
			if(i>1)d.push_back(i);
			if(i*i!=x)
				d.push_back(x/i);
		}
	while(y){
		ll g=gcd(x,y),a=x/g,b=y/g,t=b;
		for(ll i:d)
			if(a%i==0)t=min(t,b%i);
		ans+=t,y-=t*g;
	}
	printf("%lld\n",ans);
	return 0;
}