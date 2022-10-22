#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll z = 0;
const ll md = 1e9 + 7;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return (x * x) % md;
	} else {
		return (((x * x) % md) * n) % md;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , a[500] , ans = 0 , h;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	if(n == 1){
		cout<<a[0]<<endl;
		return 0;
	}
	if(n == 2){
		h = a[0] | a[1];
		cout<<h<<endl;
		return 0;
	}
	for(int i = 0 ; i < n - 2 ; i++){
		for(int j = i + 1 ; j < n - 1 ; j++){
			for(int k = j + 1 ; k < n ; k++){
				h = a[i] | a[j] | a[k];
				ans = max(h , ans);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}