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

ll a[100];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(int i = n - 1 ; i >= 0 ; i--){
			cin>>a[i];
		}
		for(int i = 0 ; i < n ; i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}