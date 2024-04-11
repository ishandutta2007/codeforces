#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 0;

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
	
	bool fard = false;
	ll n , sum = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		if(h % 2 == 1){
			fard = true;
			sum = 1 - (sum % 2);
		}
	}
	if(sum == 1 || fard == true){
		cout<<"First\n";
	} else {
		cout<<"Second\n";
	}
	return 0;
}