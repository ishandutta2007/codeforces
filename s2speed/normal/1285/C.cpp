#include<iostream>

typedef long long ll;

using namespace std;

ll mor(ll a){
	for(ll i = 1 ; ; i++){
		if(i * i >= a){
			return i;
		}
	}
}

bool aval(ll a , ll b){
	ll e = max(a , b) % min(a , b);
	if(e == 1){
		return false;
	} else if(e == 0){
		return true;
	} else {
		return aval(min(a , b) , e);
	}
}

int main(){
	ll x , a = 1 , b;
	cin>>x;
	b = x;
	ll m = mor(x);
	for(ll i = 2 ; i <= m ; i++){
		if(x % i == 0){
			if(aval(i , x / i) == false){
				a = i;
				b = x / i;
			}
		}
	}
	cout<<min(a , b)<<" "<<max(a , b)<<endl;
	return 0;
}