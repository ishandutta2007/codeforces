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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , counter = 0 , m;
		string h;
		cin>>n>>m;
		for(int i = 1 ; i < n ; i++){
			cin>>h;
			if(h[m - 1] == 'R'){
				counter++;
			}
		}
		cin>>h;
		for(int i = 1 ; i < m ; i++){
			if(h[i - 1] == 'D'){
				counter++;
			}
		}
		cout<<counter<<"\n";
	}
	return 0;
}