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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , k = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			ll inp;
			cin>>inp;
			if(inp == 1){
				k++;
			}
		}
			if(k <= n / 2){
				cout<<n / 2<<"\n";
				for(int i = 0 ; i < n / 2 ; i++){
					cout<<"0 ";
				}
				cout<<"\n";
			} else {
				if((n / 2) % 2 == 0){
					ll ans = n / 2;
					cout<<ans<<"\n";
					for(int i = 0 ; i < ans ; i++){
						cout<<"1 ";
					}
				} else {
					ll ans = n / 2 + 1;
					cout<<ans<<"\n";
					for(int i = 0 ; i < ans ; i++){
						cout<<"1 ";
					}
				}
				cout<<"\n";
			}
	}
	return 0;
}