#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

const ll z = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll a , b , h , ans = 2;
		cin>>h>>b;
		a = min(h , b);
		b = max(h , b);
		if(b % a != 0){
			cout<<-1<<"\n";
			continue;
		}
		h = b / a;
		while(h % 2 == 0){
			ans++;
			h /= 2;
		}
		if(h != 1){
			cout<<-1<<"\n";
		} else {
			cout<<ans / 3<<"\n";
		}
	}
	return 0;
}