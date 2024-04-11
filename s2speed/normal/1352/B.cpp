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
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , k;
		cin>>n>>k;
		if(n % 2 == 1 && k % 2 == 0){
			cout<<"NO"<<endl;
			continue;
		}
		if(n % 2 == 0 && k % 2 == 1){
			if(n < k * 2){
				cout<<"NO"<<endl;
				continue;
			} else {
				cout<<"YES"<<endl;
				for(int i = 0 ; i < k - 1 ; i++){
					cout<<"2 ";
				}
				cout<<n - ((k - 1) * 2)<<endl;
				continue;
			}
		}
		if(n < k){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for(int i = 0 ; i < k - 1 ; i++){
			cout<<"1 ";
		}
		cout<<n - k + 1<<endl;
	}
	return 0;
}