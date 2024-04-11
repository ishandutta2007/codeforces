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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , a , h[2];
		h[0] = 0;
		h[1] = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a;
			if(a % 2 != i % 2){
				h[a % 2]++;
			}
		}
		if(h[0] == h[1]){
			cout<<h[0]<<"\n";
		} else {
			cout<<-1<<"\n";
		}
	}
	return 0;
}