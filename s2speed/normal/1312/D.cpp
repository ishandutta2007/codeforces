#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll md = 998244353;

ll tav(ll k , ll n){
	if(n == 0) return 1;
	ll h = tav(k , n / 2);
	if(n % 2 == 1) return (((h * h) % md) * k) % md;
	return (h * h) % md;
}

ll ch(ll nn , ll k){
	ll h = 1 , t = 1 , n = min(nn , k - nn);
	for(ll i = n ; i >= 1 ; i--){
		h *= k - i + 1;
		t *= i;
		h %= md;
		t %= md;
	}
	return (h * tav(t , md - 2)) % md;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , m , imp;
	cin>>n>>m;
	imp = ((n - 2) * tav(2 , n - 3)) % md;
	cout<<(imp * ch(n - 1 , m)) % md<<endl;
	return 0;
}