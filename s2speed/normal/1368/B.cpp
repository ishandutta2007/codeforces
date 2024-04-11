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
ll a[10];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string ans;
	ll k , t = 1 , counter = 0;
	cin>>k;
	for(int i = 0 ; i < 10 ; i++){
		a[i] = 1;
	}
	while(t < k){
		t /= a[counter % 10];
		t *= a[counter % 10] + 1;
		a[counter % 10]++;
		counter++;
	}
	for(int i = 0 ; i < a[0] ; i++){
		ans += "c";
	}
	for(int i = 0 ; i < a[1] ; i++){
		ans += "o";
	}
	for(int i = 0 ; i < a[2] ; i++){
		ans += "d";
	}
	for(int i = 0 ; i < a[3] ; i++){
		ans += "e";
	}
	for(int i = 0 ; i < a[4] ; i++){
		ans += "f";
	}
	for(int i = 0 ; i < a[5] ; i++){
		ans += "o";
	}
	for(int i = 0 ; i < a[6] ; i++){
		ans += "r";
	}
	for(int i = 0 ; i < a[7] ; i++){
		ans += "c";
	}
	for(int i = 0 ; i < a[8] ; i++){
		ans += "e";
	}
	for(int i = 0 ; i < a[9] ; i++){
		ans += "s";
	}
	cout<<ans<<endl;
}