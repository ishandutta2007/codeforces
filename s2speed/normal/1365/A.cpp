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

ll m , n , a[50][50];

const ll z = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ll c = 0 , r = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cin>>a[i][j];
			}
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(a[i][j] == 1){
					r++;
					break;
				}
			}
		}
		for(int j = 0 ; j < m ; j++){
			for(int i = 0 ; i < n ; i++){
				if(a[i][j] == 1){
					c++;
					break;
				}
			}
		}
		if(min(n - r , m - c) % 2 == 1){
			cout<<"Ashish\n";
		} else {
			cout<<"Vivek\n";
		}
	}
	return 0;
}