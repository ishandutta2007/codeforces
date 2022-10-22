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

void solve(ll n){
	for(int i = 2 ; i <= sqrt(n) ; i++){
		if(n % i == 0){
			cout<<n / i<<" "<<(n / i) * (i - 1)<<"\n";
			return;
		}
	}
	cout<<"1 "<<n - 1<<"\n";
}

const ll z = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		solve(n);
	}
	return 0;
}