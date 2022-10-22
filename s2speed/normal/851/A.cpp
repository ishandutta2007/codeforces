#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 0;

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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , k , t;
	cin>>n>>k>>t;
	if(t <= k){
		cout<<t<<"\n";
	} else if(t > n) {
		cout<<n + k - t<<"\n";
	} else {
		cout<<k<<"\n";
	}
	return 0;
}