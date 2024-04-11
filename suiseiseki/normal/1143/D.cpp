#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,k;
	ll a,b;
	scanf("%lld%lld%lld%lld",&n,&k,&a,&b);
	ll temp=n*k;
	ll t[4]={a+b,a-b,-a+b,-a-b};
	ll mx=LLONG_MIN,mn=LLONG_MAX;
	for(int i=0;i<4;i++){
		ll tt=t[i];
		for(int j=0;j<n;j++,tt+=k){
			mx=max(mx,abs(__gcd(tt,temp)));
			mn=min(mn,abs(__gcd(tt,temp)));
		}
	}
	printf("%lld %lld\n",temp/mx,temp/mn);
	return 0;
}