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

ll a[200001];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , counter = 1;
		cin>>n;
		cin>>a[1];
		if(a[1] == 1){
			counter--;
		}
		for(int i = 2 ; i <= n ; i++){
			cin>>a[i];
			if(a[i - 1] == i - 1 && a[i] != i){
				counter++;
			}
		}
		if(counter < 2){
			cout<<counter<<"\n";
		} else {
			cout<<2<<"\n";
		}
	}
	return 0;
}