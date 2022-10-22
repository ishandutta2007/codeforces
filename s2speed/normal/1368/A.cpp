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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll a , b , n , counter = 0;
		cin>>a>>b>>n;
		while(max(a , b) <= n){
			if(a > b){
				b += a;
			} else {
				a += b;
			}
			counter++;
		}
		cout<<counter<<"\n";
	}
	return 0;
}