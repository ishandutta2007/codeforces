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

ll a[100000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		bool f = false;
		ll n , h = 0 , e = tav(2 , 31) , counter = 0 , v , u;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
			h = h ^ a[i];
		}
		while(e >= 1){
			v = h & e;
			if(v != 0){
				f = true;
				for(int i = 0 ; i < n ; i++){
					u = a[i] & e;
					if(u != 0){
						counter++;
					}
				}
				if((counter / 2) % 2 == 0){
					cout<<"WIN\n";
				} else {
					if(n % 2 == 0){
						cout<<"WIN\n";
					} else {
						cout<<"LOSE\n";
					}
				}
				break;
			}
			e /= 2;
		}
		if(f == false){
			cout<<"DRAW\n";
		}
	}
	return 0;
}