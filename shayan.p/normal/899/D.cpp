#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int main(){
	ll n;cin>>n;
	if(n<5){
		cout<<((n*(n-1))/2);
		return 0;
	}
	ll cop=n,last;
	ll ten=1;
	while(cop>0){
		last=cop%10;
		ten*=10;
		cop/=10;
	}
	ten/=10;
	if(last>=5){
		if(n+1==ten*10)cout<<n-(5*(ten));
		else cout<<n-(5*(ten))+1;
		return 0;
	}
	ll ans=0,num=0,N=(ten/10)*5;
	for(ll i=0;i<=n;i+=ten){//ten-1 ta ten
		ans+=(num*max((min(n,i+N-1)-i+1),(ll)0))+((num+1)*max((min(n,i+N+N-1)-(i+N)+1),(ll)0));
		num++;
		ans--;
	}
	if((n+1)%ten!=0)ans++;
	cout<<ans;
}