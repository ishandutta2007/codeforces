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

void solve(){
	ll n , q = 1;
	cin>>n;
	for(ll i = 2 ; i < (n + 1) / 2 ; i++){
		if(__gcd(i , n - i) == 1){
			q = i;
		}
	}
	cout<<q<<" "<<n - q<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}